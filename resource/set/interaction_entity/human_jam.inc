;MAIN MENU BEGIN

{on "jam_settings" ;jam settings

	{set "gun_jamming_enabled" 1} ;Disable/Enable Gun Jamming.
	
	;Animations

	{set "jam_fix_animations" 0} ;units get a reloading animation when trying to fix the weapon jam.

	;Random/Enviroment Jam Modifiers
	
	{set "repeat_jam_chance_randomizer" 1} ;randomly gives decreased or increased proabability of jamming after it is fixed.
	
	;Terrain Influence

	{set "terrain_influence" 1} ;when soldiers are LYING DOWN, on snow or swamps,sand,mud, and shallow water they will be more at risk of jamming until they squat or stand up.
	
	;Fix Timer

	{set "random_fix_timer" 1} ;Random jam fix timers disable to set to manual timer search for set_manualtimer

	;HangFire
	
	{set "hangfire" 1} ;randomly forces a delay to gunfire, could be potentially dangerous, as the surplus ammo could damage the barrel doing damage to the soldier's hands.
}

{on "call_for_jamming"
	{tags add "call_for_jamming"}
}
 
{on "jam_modifiers_menu" 
	{if "repeat_jam_chance_randomizer" 
		{if tagged "jam_cautious" 
			{if tagged "call_for_jamming" 
				{if rand 0.7 
					{call_synced "call_for_jamming"}
				}
			}
		}
	} ;decrease jam
	{if "repeat_jam_chance_randomizer" 
		{if tagged "jam_reckless" 
			{if tagged "call_for_jamming" 
				{if rand 0.0055 
					{call_synced "call_for_jamming"}
				}
			}
		}
	} ;increase jam
}

;MAIN MENU END

;TERRAIN JAM INFLUENCE BEGIN

{on "terrain_jam_output"
	{if "terrain_influence"
		{if lying 
			{if terrain_fx "shallow_water" 
				{tags add "call_for_jamming"} 
				{start_sound "human/move/lying/shallow_water"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Water Interupts Cycle"}
			}
			{if terrain_fx "water" 
				{tags add "call_for_jamming"} 
				{start_sound "swim"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Water Interupts Cycle"}
			}
			{if terrain_fx "puddle" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/puddle"}
				{start_sound "gear_rattle_normal"}					
				{damage_report "body" "<c(FFA500)>Water and Mud Interupts Cycle"}
			}
			{if terrain_fx "swamp" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/shallow_water"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Water and Muck Interupts Cycle"}
			}
			
			{if terrain_fx "snow" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/snow"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Snow Interupts Cycle"}
			}
			{if terrain_fx "ice" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/ice"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Snow Interupts Cycle"}
			}
			{if terrain_fx "bridge_snow" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/snow"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Snow Interupts Cycle"}
			}
			
			{if terrain_fx "sand" 
				{tags add "call_for_jamming"} 
				{start_sound "human/move/lying/ground"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Sand Interupts Cycle"}
			}
			{if terrain_fx "rock" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/ground"}
				{start_sound "gear_rattle_normal"} 
				{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
			}
			{if terrain_fx "ground" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/ground"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
			}
			{if terrain_fx "mud" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/mud"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Mud Interupts Cycle"}
			}
			{if terrain_fx "grass" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/grass"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
			}
			
			{if terrain_fx "bridge" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/road"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
			}
			{if terrain_fx "bridge_wood" 
				{start_sound "human/move/lying/road"}
				{start_sound "gear_rattle_normal"}
				{start_sound "human/move/snow"} 
				{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
			}
			{if terrain_fx "bridge_steel" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/metal"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
			}
		
			{if terrain_fx "road" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/road"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
			}
			{if terrain_fx "country_road" 
				{tags add "call_for_jamming"}
				{start_sound "human/move/lying/ground"}
				{start_sound "gear_rattle_normal"}
				{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
			}
		}	
	}
}

{on "terrain_influence_check"
	{if "terrain_influence"
		{if lying 
			{if terrain_fx "shallow_water" 
				{if rand 0.0025 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "water" 
				{if rand 0.01 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "puddle" 
				{if rand 0.0035 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "swamp" 
				{if rand 0.0045 
					{call_synced "terrain_jam_output"}
				}
			}
			
			{if terrain_fx "snow" 
				{if rand 0.0035 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "ice" 
				{if rand 0.0025 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "bridge_snow" 
				{if rand 0.0035 
					{call_synced "terrain_jam_output"}
				}
			}
			
			{if terrain_fx "sand" 
				{if rand 0.0045 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "rock" 
				{if rand 0.0030 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "ground" 
				{if rand 0.0030 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "mud" 
				{if rand 0.0045 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "grass" 
				{if rand 0.0035 
					{call_synced "terrain_jam_output"}
				}
			}
			
			{if terrain_fx "bridge" 
				{if rand 0.0030 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "bridge_wood" 
				{if rand 0.0030 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "bridge_steel" 
				{if rand 0.0030 
					{call_synced "terrain_jam_output"}
				}
			}
		
			{if terrain_fx "road" 
				{if rand 0.0030 
					{call_synced "terrain_jam_output"}
				}
			}
			{if terrain_fx "country_road" 
				{if rand 0.0035 
					{call_synced "terrain_jam_output"}
				}
			}
		}	
	}
}

;TERRAIN JAM INFLUENCE WHILE LYING END

;LOGICAL CHECKS BEGIN

(define "tags_remove" ; so weapons switch their jamming data on weapon switch.
	{if tagged %iftag
		{tags remove %tagrem}
	}
)

{on "link_weapon"
	{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
		{with_effector
			{call_synced "link_human"}
		}
	}
	{if stuff "pistol" ;pistol
		{tags add "has_pistol"} 
		{tags add "jammable"} 
		("tags_remove" iftag("has_pistol") tagrem("has_smg has_rifle has_sniper has_shotgun has_mgun")) 
	else stuff "smg" ;smg
		{tags add "has_smg"} 
		{tags add "jammable"}
		("tags_remove" 	iftag("has_smg") tagrem("has_pistol has_mgun has_rifle has_shotgun has_sniper")) 
	else stuff "rifle" ;rifle
		{tags add "has_rifle"} 
		{tags add "jammable"}  
		("tags_remove" iftag("has_rifle") tagrem("has_pistol has_mgun has_smg has_shotgun has_sniper"))
	else stuff "ptr" ;anti tank rifle
		{tags add "has_ptr"} 
		("tags_remove" iftag("has_ptr") tagrem("has_pistol has_rifle jammable has_mgun has_smg has_shotgun has_sniper")) 
	else stuff "sniper" ;sniper
		{tags add "has_rifle"} 
		{tags add "jammable"}  
		("tags_remove" iftag("has_rifle") tagrem("has_pistol has_mgun has_smg has_shotgun has_sniper")) 
	else stuff "shotgun" ;shotgun
		{tags add "has_shotgun"} 
		{tags add "jammable"} 
		("tags_remove" iftag("has_shotgun") tagrem("has_pistol has_mgun has_smg has_rifle has_sniper")) 
	else stuff "mgun" ;mgun
		{tags add "has_mgun"} 
		{tags add "jammable"} 
		("tags_remove" iftag("has_mgun") tagrem("has_pistol has_smg has_rifle has_sniper has_shotgun")) 
	else stuff "flame_thrower"
		{tags add "has_mgun"} 
		("tags_remove" iftag("has_flamethrower") tagrem("has_mgun has_pistol has_smg has_rifle has_sniper has_shotgun")) ;;;;;;;;;;;NOTJAMMABLE;;;;;;;;;;;
	else
	} 
}

;LOGICAL CHECKS END

;WEAPON JAM RATE PER CLASS BEGIN
	;set how often certain types of weapons will jam set_weapontype 0.0001 ;.001% chance 0.0005 ;.005% chance

{on "weapon_jam"
	{if "gun_jamming_enabled" 
		{if bone "foresight3" ;pistol
			{if rand 0.001 
				{call_synced "call_for_jamming"}
			}
		else bone "Foresight11"  ;smg
			{if rand 0.001 
				{call_synced "call_for_jamming"}
			}
		else bone "foresight12" ;rifle
			{if rand 0.0007 
				{call_synced "call_for_jamming"}
			}
		else bone "foresight14" ;mgun
			{if rand 0.001 
				{call_synced "call_for_jamming"}
			}
		}
	}
}

;WEAPON JAM RATE PER CLASS EMD

;WEAPON JAM FIX LOGIC BEGIN

{on "jam_cautious"
	{attack_save}
	{damage_report "body" "<c(FFA500)>Gun Fixed: Less Jam"}
	{tags add "jam_cautious"} 
}

{on "jam_reckless"
	{attack_load}
	{damage_report "body" "<c(FFA500)>Gun Damaged: Increased Jam"}
	{tags add "jam_reckless"} 
}

{on "jam_fixed"
	{attack_save}
	{damage_report "body" "<c(FFA500)>Gun Repaired: Minimal Jamming For Now"}
	{tags add "jam_fixed"} 
}

{on "jam_fix" ;FIXING THE JAM
	{if tagged "fixed"
		{if tagged "jam"
			{tags remove "jam"}
			{tags remove "fixed"}
			{start_sound "weapon/reload"}
			{weapon_work "hand_right" 1}
			{if not dead 
				{if able "select" 
					{if not senseless ;so the knocked out and dead wont be able to fix it they will restart
						{damage_report "body" "<c(FFA500)>Jam Fixed"}
					}
				}
			}
			{talk "jubilation"}
			{ani_stop "squat_reload_bazooka"}
			{ani_stop "lie_reload_bazooka"} 
			{if not dead 
				{if able "select" 
						{if not senseless 
						{if "repeat_jam_chance_randomizer"
							{if rand 0.1 
								{call_synced "jam_cautious"}
							else rand 0.1 
								{call_synced "jam_reckless"}
							else rand 0.05
								{call_synced "jam_fixed"}
							}
						}
					}
				}
			}
		}
	}
}

;WEAPON JAM FIX LOGIC END

;WEAPON HANGFIRE LOGIC BEGIN
 
{on "hang_fire_work_0-2"
	{delay 0.2
		{weapon_work "hand_right" 1}
		{tags remove "hangfire"}
	}
}

{on "hang_fire_work_1"
	{delay 1.0
		{weapon_work "hand_right" 1}
		{tags remove "hangfire"}
	}
}

{on "hang_fire_work_1-5"
	{delay 1.5
		{weapon_work "hand_right" 1}
		{tags remove "hangfire"}
	}
}
 
{on "hangfire"
	{tags add "hangfire"}
	{weapon_work "hand_right" 0} ;due to surplus ammo the gun will click but have a delay before firing, this could be potentially dangerous
	{if not tagged "jam_reckless"
		{damage_report "body" "<c(FFA500)>Hangfire"}
	}
	{if tagged "jam_reckless"
		{damage_report "body" "<c(FFA500)>Hangfire From Damaged Gun"}
	}
	{if rand 0.4
		{call_synced "hang_fire_work_0-2"}
	else rand 0.4
		{call_synced "hang_fire_work_1"}
	else rand 0.4
		{call_synced "hang_fire_work_1-5"}
	else
		{call_synced "squib"}
	}
}

{on "squib"
	{delay 1.5 
		{damage_report "body" "<c(FFA500)>Squib Deflagrate: 50 Damage"}
		{view start "grenade_debris"}
		("human_health" c(50)) ;hangfire damage to hands
		{delay 0.3 
			{talk "injuring"}
		}
		{delay 5 
			{weapon_work "hand_right" 1}
			{tags remove "hangfire"}
			{damage_report "body" "<c(FFA500)>Squib Damages Gun: Partial Repair"}
			{tags add "jam_reckless"} ;needs updated to severe or gun destruction
		}
	}
}

;WEAPON HANGFIRE LOGIC END

;WEAPON JAM CHECK BEGIN

{on fire "hand_right"
	{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
			{with_effector
				{call "fire"}
			}
	}
	{if tagged "jammable" ;only jammable weapons are to be jammed.
		{call "jam_settings"} ;checks whether gun jamming is enabled or not.
		{if "gun_jamming_enabled" 
			{if tagged "has_smg" 
				{call "weapon_jam"}
			}
			{if tagged "has_rifle" 
				{call "weapon_jam"}
			}
			{if tagged "has_pistol" 
				{call "weapon_jam"}
			} 
			{if tagged "has_mgun" 
				{call "weapon_jam"}
			} 
			{if tagged "has_shotgun" 
				{call "weapon_jam"}
			}
			{call "terrain_influence_check"} ;to check the other jam values
			{call "jam_modifiers_menu"} ;to check the other jam values
			{if "hangfire"
				{if not tagged "jam_reckless"
					{if rand 0.0002 
						{call_synced "hangfire"}
					}
				} ;HANGFIRE 0.0002 chance
				{if tagged "jam_reckless"
					{if rand 0.0021 
						{call_synced "hangfire"}
					}
				} ;damaged gun
			}
		}
		{if not tagged "hangfire"
			{if not tagged "jam_fixed" 
				{if not tagged "fixed" 
					{if tagged "call_for_jamming" 
						{tags remove "call_for_jamming"} ;so the weapon can be jammed again some time later if not tagged "jam_fixed"
						{weapon_work "hand_right" 0} ;stops the weapon from firing
						{tags add "jam"} 
						{delay 1.6 
							{damage_report "body" "<c(FFA500)>Jammed"}
						}
						{delay 2.0 
							{talk "injuring"}
						} 
						{delay 3.5 
							{if "jam_fix_animations"
								{if able "select" 
									{tags add "jam"} 
									{ani_play "squat_reload_bazooka" 1.0 loop} 
								}
							}
						} ;animations of fixing the weapon
							
						;Fixing the Jam ;get rid of the shell that jammed your weapon.
							
						{delay 3.51 
							{if tagged "jam"
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									}
								}
							} 
						}
						{delay 3.61 
							{if tagged "jam"
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									}
								}
							}
						} 
						{delay 3.71
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									}
								}
							}
						} 
						{delay 3.81
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									}
								}
							} 
						} 
						{delay 4.41
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									} 
								}
							} 
						} 
						{delay 5.31
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									}
								}
							} 
						} 
						{delay 6.61
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									}
								}
							} 
						} 
						{delay 7.81
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									} 
								}
							} 
						} 
						{delay 8.41
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									} 
								}
							} 
						} 
						{delay 9.31
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									}
								}
							} 
						} 
						{delay 10.61
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									} 
								}
							} 
						} 
						{delay 11.81
							{if tagged "jam" 
								{if not able "select" 
								{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									} 
								}
							} 
						} 
						{delay 12.41
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									} 
								}
							} 
						} 
						{delay 13.41
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									} 
								}
							} 
						} 
						{delay 14.41
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									} 
								}
							} 
						} 
						{delay 15.41
							{if tagged "jam" 
								{if not able "select" 
									{tags remove "jam"}
									{throw_on_ground}
									{delay 0.01 
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
										}
									}
								}
							} 
						} 
						{if "random_fix_timer" ;Random Jam fix timers
							{if rand 0.7 
								{call_synced "jam_fix_8"}
							else rand 0.5
								{call_synced "jam_fix_3-7"}
							else 
								{call_synced "jam_fix_15"}
							}
						}
					}
				} 
			} 
		}
	}
}

{on "jam_fix_3-7"
	{delay 3.7 
		{tags add "fixed"}
		{call_synced "jam_fix"}
	}
}

{on "jam_fix_8"
	{delay 8
		{tags add "fixed"}
		{call_synced "jam_fix"}
	}
}
{on "jam_fix_15"
	{delay 15 
		{tags add "fixed"}
		{call_synced "jam_fix"}
	}
}

		
;WEAPON JAM CHECK END