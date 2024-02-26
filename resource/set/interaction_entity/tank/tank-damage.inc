;/*=========== Piercing Damage Begin ===========*/
	(define "damage_process_pierce" 					;// {on pierce} shell penetrates specific volume
		{if stuff "%staff"
            (include "penetration-display.inc")		;// inserts code from other file for pierce, blast and other damage events
			{if not "pierced_processed"					;// check that process has not already run for the same event (prevents double damage for same projectile)
				{set "pierced_processed" 1}
				{if rand %tag_test {tags add "tag_test"}}   ;// Used for testing damage_process_pierce.
				{vehicle_health_damage_pierce}
				{if not component "shield"				;// prevents the pen FX from spawning when hitting shield components
					{if not material "wood"
						{if not volume "armor"
							{if not tagged "pen_fx"						;// checks to ensure fx is not played more than once from the same shell / penetration
								{tags add "pen_fx"}
								{delay 0.05
									{tags remove "pen_fx"}
								}
								{burn fx "metal_hit_penetration_%pen_fx" time 1 fake}
								{if stuff "shell"
									{burn fx "smoke_after_pen" time 5 fake}
								else stuff "rocketlauncher"
									{burn fx "smoke_after_pen" time 5 fake}
								}
								{if component "body"
									{if stuff "shell"
										{view start "smoke_after_pen_hatch"}
										{delay 7 2
											{view pause "smoke_after_pen_hatch"}
										}
									else stuff "rocketlauncher"
										{view start "smoke_after_pen_hatch"}
										{delay 7 2
											{view pause "smoke_after_pen_hatch"}
										}
									}
								else component "turret"
									{if stuff "shell"
										{view start "smoke_after_pen_hatch"}
										{delay 7 2
											{view pause "smoke_after_pen_hatch"}
										}
									else stuff "rocketlauncher"
										{view start "smoke_after_pen_hatch"}
										{delay 7 2
											{view pause "smoke_after_pen_hatch"}
										}
									}
								}
								{start_sound "hit/steel/penetrate/%pen_sound"}
								{start_sound "hit/steel/penetrate/bkg/%pen_sound"}
							}
						}
					}
				}
				{if component "body"
					{if rand (* %knock_out 1)
						{call_synced "knock_out"}
					}
					{if rand (* %internal_fire 1)
						{call_synced "fire_knock_out"}
					}
					{if tagged "death_counter_start"
						{call "death_counter"}
					}
					{call "death_counter_check"}
					{if tagged "internal_fire"
						{burn fx "smoke_dead_tank1"}
					}
					{if material "wood"
						;// do nothing
					}

					{if operatable
						{if rand (* %kill_crew 0.8)		{call_synced "kill_driver"}}
						{if rand (* %kill_crew 0.4)		{call_synced "kill_gunner"}}
						{if rand (* %kill_crew 0.4)		{call_synced "kill_gunner2"}}
						{if rand (* %kill_crew 0.8)		{call_synced "kill_gunner3"}}
						{if rand (* %kill_crew 0.4)		{call_synced "kill_gunner4"}}
						{if rand (* %kill_crew 0.4)		{call_synced "kill_gunner5"}}
						{if rand (* %kill_crew 0.4)		{call_synced "kill_charger"}}
						{if rand (* %kill_crew 0.8)		{call_synced "kill_charger2"}}
						{if rand (* %kill_crew 0.8)		{call_synced "kill_charger3"}}
						{if rand (* %kill_crew 0.4)		{call_synced "kill_charger4"}}
						{if rand (* %kill_crew 0.4)		{call_synced "kill_commander"}}

						{kill_delay "crew_shock_time"}		;// resets shock time
						{call "crew_stunned"}
						{delay %crew_shock_time 1 "crew_shock_time"
							{call "crew_revive"}
						}
						{delay (* %crew_shock_time 0.5) 0.5 "crew_shock_time"
							{call "driver_revive"}
						}
					}
				}

				{if component "turret"
					{if rand (* %knock_out 0.75)
						{call_synced "knock_out"}
					}
					{if rand (* %internal_fire 0.5)
						{call_synced "fire_knock_out"}
					}						
					{if tagged "death_counter_start"
						{call "death_counter"}
					}
					{call "death_counter_check"}
					{if operatable
						{if rand (* %kill_crew 0.2)		{call_synced "kill_driver"}}
						{if rand (* %kill_crew 0.8)		{call_synced "kill_gunner"}}
						{if rand (* %kill_crew 0.8)		{call_synced "kill_gunner2"}}
						{if rand (* %kill_crew 0.2)		{call_synced "kill_gunner3"}}
						{if rand (* %kill_crew 0.0)		{call_synced "kill_gunner4"}}
						{if rand (* %kill_crew 0.0)		{call_synced "kill_gunner5"}}
						{if rand (* %kill_crew 0.8)		{call_synced "kill_charger"}}
						{if rand (* %kill_crew 0.4)		{call_synced "kill_charger2"}}
						{if rand (* %kill_crew 0.4)		{call_synced "kill_charger3"}}
						{if rand (* %kill_crew 0.0)		{call_synced "kill_charger4"}}
						{if rand (* %kill_crew 0.8)		{call_synced "kill_commander"}}

						{kill_delay "crew_shock_time"}		;// resets shock time
						{call_synced "crew_stunned"}
						{delay %crew_shock_time 1 "crew_shock_time"
							{call_synced "crew_revive"}
						}
						{delay (* %crew_shock_time 0.5) 0.5 "crew_shock_time"
							{call_synced "driver_revive"}
						}
					}
				}

				{if component "mantlet"
					{##if rand %pierce_mantlet__mantlet_jam
						{call_synced "mantlet_jam"}				;// temporarily disables gun elevation (up/down movement)
					}
					{if not "turret"						;// tank has no turret. For tank destroyers. {props "-turret"}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_driver"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_gunner"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_gunner2"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_gunner3"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_gunner4"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_gunner5"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_charger"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_charger2"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_charger3"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_charger4"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_commander"}}

						{kill_delay "crew_shock_time"}
						{call_synced "crew_stunned"}
						{delay %crew_shock_time 1 "crew_shock_time"
							{call_synced "crew_revive"}
						}
						{delay (* %crew_shock_time 0.5) 0.5 "crew_shock_time"
							{call_synced "driver_revive"}
						}
					}
				}

				{if volume "gun_shield"					;// for open top tank destroyers when gun shield is penetrated. (technically not the turret)
					{if not "shield_pen"
						{set "shield_pen" 1}
						{if rand (* %kill_crew 0.1)		{call_synced "kill_driver"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_gunner"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_gunner2"}}
						{if rand (* %kill_crew 0.1)		{call_synced "kill_gunner3"}}
						{if rand (* %kill_crew 0.0)		{call_synced "kill_gunner4"}}
						{if rand (* %kill_crew 0.0)		{call_synced "kill_gunner5"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_charger"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_charger2"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_charger3"}}
						{if rand (* %kill_crew 0.0)		{call_synced "kill_charger4"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_commander"}}

						{kill_delay "crew_shock_time"}
						{call_synced "crew_stunned"}
						{delay %crew_shock_time "crew_shock_time"
							{call_synced "crew_revive"}
						}
						{delay (* %crew_shock_time 0.5) 0.5 "crew_shock_time"
							{call_synced "driver_revive"}
						}
						{delay 0.5
							{set "shield_pen" 0}
						}
					}
				}
			}
		}
	)

	(define "at_grenade_pierce"						;// {on pierce} HEAT grenades penetrate specific components
		{if stuff "cumulative_charge"
			{if component "body"
				{if rand %pierce_body_brake
					{if work "body"
						{call_synced "body_break"}
					else rand %pierce_body_destroy
						{call_synced "hull_destroyed"}
					}
				else rand %pierce_body_destroy
					{if not work "body"
						{call_synced "hull_destroyed"}
					}
				}
			else component "engine"
				{if rand %pierce_engine_brake
					{if work "engine"
						{call_synced "engine_break"}
					else rand 0.5
						{call_synced "engine_destroy"}
					}
				}
			else
				{component break}
			}
		}
	)
	{on "body_break"
		{components "body" break}
	}
	{on "engine_break"
		{components "engine" break}
	}
	{on "engine_destroy"
		{components "engine" destroy}
	}


;/*=========== Piercing Damage End ===========*/

;/*=========== Blast Damage Begin ===========*/

	(define "damage_process_blast"						;// {on blast} blast-wave contacts a specific volume
		{if volume "body"
			{if tagged "death_counter_start"
				{if not tagged "death_blast_delay"
					{call "death_counter_blast"}
					{tags add "death_blast_delay"}
					{delay 0.5
						{tags remove "death_blast_delay"}
					}
				}
			}
			{call "death_counter_check"}
			{if operatable
				{if min_energy %blast_energy
					{if rand (* %kill_crew 1)		{call_synced "kill_driver"}}
					{if rand (* %kill_crew 0.5)		{call_synced "kill_gunner"}}
					{if rand (* %kill_crew 0.5)		{call_synced "kill_gunner2"}}
					{if rand (* %kill_crew 1)		{call_synced "kill_gunner3"}}
					{if rand (* %kill_crew 0.5)		{call_synced "kill_gunner4"}}
					{if rand (* %kill_crew 0.5)		{call_synced "kill_gunner5"}}
					{if rand (* %kill_crew 0.5)		{call_synced "kill_charger"}}
					{if rand (* %kill_crew 1)		{call_synced "kill_charger2"}}
					{if rand (* %kill_crew 1)		{call_synced "kill_charger3"}}
					{if rand (* %kill_crew 0.5)		{call_synced "kill_charger4"}}
					{if rand (* %kill_crew 0.5)		{call_synced "kill_commander"}}

					{if not "already_blasted"					;// prevents secondary (smaller) blast-waves from overriding primary (larger) blast-wave
						{set "already_blasted" 1}
						{if rand %crew_shock_chance
							{call_synced "crew_shot_chance"}
							{delay %crew_shock_time 1 "crew_shock_time"
								{call_synced "crew_revive"}
							}
							{delay (* %crew_shock_time 0.5) 0.5 "crew_shock_time"
								{call_synced "driver_revive"}
							}
						}
						{delay 0.25
							{set "already_blasted" 0}
						}
					}
				}
			}

		else volume "turret"
			{if tagged "death_counter_start"
				{if not tagged "death_blast_delay"
					{call "death_counter_blast"}
					{tags add "death_blast_delay"}
					{delay 0.5
						{tags remove "death_blast_delay"}
					}
				}
			}
			{call "death_counter_check"}
			{if operatable
				{if min_energy %blast_energy
					{if rand (* %kill_crew 0.4) 	{call_synced "kill_driver"}}
					{if rand (* %kill_crew 1)		{call_synced "kill_gunner"}}
					{if rand (* %kill_crew 1)		{call_synced "kill_gunner2"}}
					{if rand (* %kill_crew 0.4)		{call_synced "kill_gunner3"}}
					{if rand (* %kill_crew 0.1)		{call_synced "kill_gunner4"}}
					{if rand (* %kill_crew 0.1)		{call_synced "kill_gunner5"}}
					{if rand (* %kill_crew 1)		{call_synced "kill_charger"}}
					{if rand (* %kill_crew 0.5)		{call_synced "kill_charger2"}}
					{if rand (* %kill_crew 0.5) 	{call_synced "kill_charger3"}}
					{if rand (* %kill_crew 0.1) 	{call_synced "kill_charger4"}}
					{if rand (* %kill_crew 1) 		{call_synced "kill_commander"}}

					{if not "already_blasted"					;// prevents secondary (smaller) blast-waves from overriding primary (larger) blast-wave
						{set "already_blasted" 1}
						{if rand %crew_shock_chance
							{call_synced "crew_shot_chance"}
							{delay %crew_shock_time 1 "crew_shock_time"
								{call_synced "crew_revive"}
							}
							{delay (* %crew_shock_time 0.5) 0.5 "crew_shock_time"
								{call_synced "driver_revive"}
							}
						}
						{delay 0.25
							{set "already_blasted" 0}
						}
					}
				}
			}

		else volume "mantlet"
			{if operatable
				{if min_energy %blast_energy
					{if not "turret"							;// checks if vehicle has a turret code meant only for tank destroyers without a turret
						{if rand (* %kill_crew 0.5)		{call_synced "kill_driver"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_gunner"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_gunner2"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_gunner3"}}
						{if rand (* %kill_crew 0.1)		{call_synced "kill_gunner4"}}
						{if rand (* %kill_crew 0.1)		{call_synced "kill_gunner5"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_charger"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_charger2"}}
						{if rand (* %kill_crew 0.5)		{call_synced "kill_charger3"}}
						{if rand (* %kill_crew 0.1)		{call_synced "kill_charger4"}}
						{if rand (* %kill_crew 0.25)	{call_synced "kill_commander"}}
					}
					{if not "already_blasted"					;// prevents secondary (smaller) blast-waves from overriding primary (larger) blast-wave
						{set "already_blasted" 1}
						{if rand %crew_shock_chance
							{call_synced "crew_shot_chance"}
							{delay %crew_shock_time 1 "crew_shock_time"
								{call_synced "crew_revive"}
							}
							{delay (* %crew_shock_time 0.5) 0.5 "crew_shock_time"
								{call_synced "driver_revive"}
							}
						}
						{delay 0.25
							{set "already_blasted" 0}
						}
					}
				}
			}

		else volume "trackleft"
			;//do nothing
		else volume "trackright"
			;//do nothing
		else volume "roller"
			;//do nothing
		else volume "wheel_work"
			;//do nothing
		else volume "wheel"
			;//do nothing

		else
			{if operatable
				{if min_energy %blast_energy
					{if not "already_blasted"					;// prevents secondary (smaller) blast-waves from overriding primary (larger) blast-wave
						{set "already_blasted" 1}
						{if rand %crew_shock_chance
							{call_synced "crew_shot_chance"}
							{delay %crew_shock_time 1 "crew_shock_time"
								{call_synced "crew_revive"}
							}
							{delay (* %crew_shock_time 0.5) 0.5 "crew_shock_time"
								{call_synced "driver_revive"}
							}
						}
						{delay 0.25
							{set "already_blasted" 0}
						}
					}
				}
			}
		}
	)

	{on "crew_shot_chance"
		{kill_delay "crew_shock_time"}		;// resets shock time
		{call "crew_stunned"}
	}

	{on contact												;// Adds special tag to vehicle for check on "at_grenade_blast"
		{if effector "mine grenade"
			{tags add "grenade"}
			{delay 0.25
				{tags remove "grenade"}
			}
		else effector "grenade"
			{tags add "grenade"}
			{delay 0.05
				{tags remove "grenade"}
			}
		}
	}

	(define "at_grenade_blast"								;// {on break_armor} for AT grenades that use blast and not pierce to cause damage to components
		{if name "blast"
			{if tagged "grenade"
				{set "already_blasted" 1}
				{if component "body"
					{if rand %pierce_body_brake
						{if work "body"
							{call_synced "body_break"}
						else
							{call_synced "hull_destroyed"}
						}
					}
				else component "engine"
					{if rand %pierce_engine_brake
						{if work "engine"
							{call_synced "engine_break"}
						else
							{call_synced "engine_destroy"}
						}
					}
				else volume "hatch"
					{components "turret" break}
				else volume "cupola"
					{components "turret" break}
				else
					{component break}
				}
				{delay 0.25
					{set "already_blasted" 0}
				}
			}
		}
	)

;/*=========== Blast Damage End ===========*/

	(define "process_hit"					;// {on bullet_hit} shell hits entity
		{if stuff "pierce"
			{if not stuff "auto"
				{if not stuff "heat_shell"
					{if stuff "shell %size"
						{delay 0.01
							{if not tagged "pen_fx"
								{start_sound "hit/steel/ricochet/%sound"}
								{start_sound "hit/steel/ricochet/bkg/%sound"}
							}
						}
					}
				}
			}
		}
	)

;/*=========== Bullet Hit Probability Begin ===========*/

{on bullet_hit
	("process_hit"
		size(size1)					;// 37-74mm cannon shells
		sound(small)
	)
	("process_hit"
		size(size2)					;// 75-104mm cannon shells
		sound(medium)
	)
	("process_hit"
		size(size3)					;// 105-149mm cannon shells
		sound(large)
	)
	("process_hit"
		size(size4)					;// 150-169mm cannon shells
		sound(large)
	)
	("process_hit"
		size(size5)					;// 170mm+ cannon shells
		sound(large)
	)
}

;/*=========== Bullet Hit Probability End ===========*/

;/*=========== Blast Hit Probability Begin ===========*/

{on blast_hit										;// blast-wave hits any part of entity
}

;/*=========== Blast Hit Probability End ===========*/

;/*=========== Stun Begin ===========*/

{on "crew_stunned"									;// disables vehicle movement and weapons
	{if work "mover"
		{chassis_work 0}
		{tags add "stopped"}
	}
	{if work "turret"
		{ik_enable "turret" 0}
		{tags add "turret_jammed"}
	}
	{weapon_work "gun" 0}
	{weapon_work "gun1" 0}
	{weapon_work "gun2" 0}
	{weapon_work "gun3" 0}
	{weapon_work "mgun" 0}
	{weapon_work "mgun1" 0}
	{weapon_work "mgun2" 0}
	{weapon_work "mgun3" 0}
	{weapon_work "mgun4" 0}
	{weapon_work "mgun5" 0}
	{call "shock_check"}
}

{on "driver_revive"
	{if tagged "stopped"
		{tags remove "stopped"}
		{if work "mover"
			{if not tagged "engine_brake"
				{if "engine_on"
					{if not tagged "wheel_destroyed"
						{chassis_work 1}
					}
				}
			}
		}
	}
}

{on "crew_revive"									;// enables vehicle movement and weapons after being temporarily disabled
	{if not tagged "deactivated"					;// checks to make sure the hull is not broken or destroyed
		{if not tagged "gun_brake"
			{weapon_work "gun" 1}
		}
		{weapon_work "gun1" 1}
		{weapon_work "gun2" 1}
		{weapon_work "gun3" 1}
		{weapon_work "mgun" 1}
		{weapon_work "mgun1" 1}
		{weapon_work "mgun2" 1}
		{weapon_work "mgun3" 1}
		{weapon_work "mgun4" 1}
		{weapon_work "mgun5" 1}


		{if tagged "turret_jammed"
			{tags remove "turret_jammed"}
			{if tagged "turret_brake"				;// checks if the turret is broken
				;//do nothing
			else tagged "turret_stopped_by_body"	;// checks if the body is broken
				;//do nothing
			else
				{ik_enable "turret" 1}
			}
		}
	else
		{tags remove "stopped"}
		{tags remove "turret_jammed"}
	}
}

;/*=========== Stun End ===========*/

;/*=========== Ammo Break Begin ===========*/

{on "ammo_break"
	{call "stat_break"}
	{if rand 0.4
		{call_synced "ammo_explosion"}
	else
		{call_synced "pre_cookoff"}
	}
}

{on "ammo_explosion"
	{if not tagged "ammo_cooked"
		{tags add "ammo_broken"}
		{call "explosion"}
	}
}

{on "pre_cookoff"						;// Main cookoff decider script (decides which cookoff path is taken)
	{if not tagged "ammo_cooked"
		{call "stat_break"}
		{tags add "pre_cookoff"}
		{able minimap 0}
		{able select 0}
		{able repaired 0}
		{tags add "ammo_cooked"}
		{tags add "no_scavenge"}
		{link_sound "cook_off" "detonation/cook_off/cook"}
		{link_sound "cook_off" "detonation/cook_off/transition"}
		{link_sound "burnup_ammo" "detonation/cook_off/burn_ammo"}
		{call "engine_off"}
		{if tagged "vehicle_destroyed" ;// vehicle already burning so no build up
			;//random explosion timer
			{if rand 0.25
				{delay 7 7
					{call_synced "cookoff_rand_explosion"}
				}
			}

			;//explosion and slightly delayed normal cookoff
			{if rand 0.7
				{call_synced "rand_hatch_normal_explosion"}

			;//instant normal cookoff
			else
				{call_synced "normal_cookoff"}
			}
		else
			;// 1st Path pre smoke cookoff
			{if rand 0.3

				;//random explosion timer
				{if rand 0.25
					{delay 11 11
						{call_synced "cookoff_rand_explosion"}
					}
				}

				;// explosion at hatch
				{call_synced "rand_hatch_pre_smoke_explosion"}

			;// 2nd Path to pre smoke cookoff
			else rand 0.6

				;//random explosion timer
				{if rand 0.25
					{delay 12 12
						{call_synced "cookoff_rand_explosion"}
					}
				}

				;//delayed presmoke cookoff
				{if rand 0.3
					{call_synced "rand_pre_smoke_delay"}

				;//instant presmoke cookoff
				else
					{call_synced "rand_pre_smoke"}
				}

			;// 3rd Path to normal cookoff path
			else

				;//random explosion timer
				{if rand 0.25
					{delay 7 7
						{call_synced "cookoff_rand_explosion"}
					}
				}

				;//explosion and slightly delayed normal cookoff
				{if rand 0.7
					{call_synced "rand_hatch_normal_explosion"}

				;//instant normal cookoff
				else
					{call_synced "normal_cookoff"}
				}
			}
		}
	}
}

{on "pre_smoke_cookoff"		;// pre-smoke delayed normal cookoff path
	{if not tagged "pre_smoke_cookoff"
		{tags add "pre_smoke_cookoff"}
		{view start "cooking_presmoke_1"}
		{start_sound "detonation/cook_off/internal_explosions"}
		{delay 3
			{call "burn_emit"}
		}

		;// build up of smoke to cookoff
		{delay 8 6 "cookoff4"
			{if not able "exploded"
				{view stop "cooking_presmoke_1"}
				{view start "cooking_presmoke_2"}
				{start_sound "detonation/cook_off/internal_explosions"}

				{if rand 0.3
					{call_synced "rand_barrel_fire"}
				}

				{delay 1.5 0.5 "cookoff5"
					{if tagged "barrel_fire"
						{view pause "cooking_barrel_aftersmoke"}
						{view start "cooking_barrel_smoke"}
					}
					{view stop "cooking_presmoke_2"}
					{view start "cooking_presmoke_3"}
					{start_sound "detonation/cook_off/internal_explosions"}

					{delay 0.4 0.2
						{start_sound "detonation/cook_off/internal_explosions"}
					}
					{delay 0.8 0.2
						{start_sound "detonation/cook_off/internal_explosions"}
					}
					{delay 1.5 0.5 "cookoff6"
						{view stop "cooking_presmoke_3"}
						{call "normal_cookoff"}
					}
				}
			}
		}
	}
}

{on "normal_cookoff"		;//normal cookoff, instant
	{if not able "exploded"

		{if rand 0.5
			{call_synced "rand_hatch_explosion"}
		}
		{if rand 0.4
			{call_synced "turret_ring_fire"}
		}
		{if tagged "barrel_fire"					;// barrel smoke turns into fire
			{view stop "cooking_barrel_smoke"}
			{view start "cooking_barrel_fire"}
		}

		{fire radius 4 time 4 heating 0.5}
		{kill_crew}
		{clear_inventory}
		{link_sound "hatch_fire" "fire/loops/big"}
		{view start "cooking_high"}
		{ani_wind "open" end}
		{ani_wind "open1" end}
		{play_sound "cook_off" 1}
		{play_sound "burnup_ammo" 1}

		{delay 10 2 "cookoff7"
			{view start "cooking_high_2"}
			{view start "cooking_turret_smoke"}
			{view stop "cooking_high"}
			{view stop "cooking_turret_fire"}
			{stop_sound "burnup_ammo"}
			{start_sound "detonation/cook_off/transition"}

			{delay 4 2 "cookoff8"
				{stop_sound "cook_off"}
				{start_sound "detonation/cook_off/transition"}
				{view start "cooking_hatch_fire"}
				{play_sound "hatch_fire" 1}
				{view stop "cooking_high_2"}

				{if tagged "barrel_fire"
					{view start "cooking_barrel_aftersmoke"}
					{view stop "cooking_barrel_fire"}
				}
				{delay 60 10 "cookoff9"
					{view start "cooking_hatch_smoke"}
					{view stop "cooking_hatch_fire"}
					{stop_sound "hatch_fire"}
				}
			}
		}
	}
}

{on "rand_pre_smoke_delay"
	{delay 1 "cookoff1"
		{call "burn_emit"}
		{delay 2 "cookoff2"
			{ani_play "open" +1.0 resume}
			{call "pre_smoke_cookoff"}
		}
	}
}

{on "rand_pre_smoke"
	{call "pre_smoke_cookoff"}
	{ani_wind "open" end}
	{ani_wind "open1" end}
}

{on "rand_hatch_normal_explosion"
	{spawn "fire_cooking_explosion" "FXfire3"}
	{start_sound "detonation/he_size1/bkg/"}
	{ani_wind "open" end}
	{ani_wind "open1" end}
	{call "kill_crew_chance"}
	{call "burn_emit"}
	{delay 0.8 0.4 "cookoff3"
		{call "normal_cookoff"}
	}
}

{on "rand_hatch_pre_smoke_explosion"
	{spawn "fire_cooking_explosion" "FXfire3"}
	{start_sound "detonation/he_size1/bkg/"}
	{call "kill_crew_chance"}
	{call "pre_smoke_cookoff"}
	{ani_wind "open" end}
	{ani_wind "open1" end}
}

{on "rand_barrel_fire"
	{view start "cooking_barrel_aftersmoke"}
	{tags add "barrel_fire"}
}

{on "rand_hatch_explosion"
	{spawn "fire_cooking_explosion" "FXfire3"}		;// hatch explosion
	{start_sound "detonation/he_size1/bkg/"}
}

{on "turret_ring_fire"
	{view start "cooking_turret_fire"}				;// turret ring fire
}

{on "cookoff_rand_explosion"	;// calls random explosion that can happen during cookoff
	{tags add "ammo_broken"}
	{call "kill_cookoff"}
	{call "explosion"}
}

{on "kill_cookoff"			;//stops all cookoff delays and sounds
	{kill_delay "cookoff1"}
	{kill_delay "cookoff2"}
	{kill_delay "cookoff3"}
	{kill_delay "cookoff4"}
	{kill_delay "cookoff5"}
	{kill_delay "cookoff6"}
	{kill_delay "cookoff7"}
	{kill_delay "cookoff8"}
	{kill_delay "cookoff9"}
	{tags add "cookoff_killed"}
	{stop_sound "cook_off"}
	{stop_sound "burnup_ammo"}
	{start_sound "detonation/cook_off/transition"}
}

{on "kill_crew_chance"
	{if rand 0.75	{call_synced "kill_gunner"}}
	{if rand 0.75	{call_synced "kill_gunner2"}}
	{if rand 0.75	{call_synced "kill_gunner3"}}
	{if rand 0.75	{call_synced "kill_gunner4"}}
	{if rand 0.75	{call_synced "kill_gunner5"}}
	{if rand 0.75	{call_synced "kill_charger"}}
	{if rand 0.75	{call_synced "kill_charger2"}}
	{if rand 0.75	{call_synced "kill_charger3"}}
	{if rand 0.75	{call_synced "kill_charger4"}}
	{if rand 0.75	{call_synced "kill_commander"}}
	{if rand 0.75	{call_synced "kill_driver"}}
}

;/*=========== Ammo Break End ===========*/
