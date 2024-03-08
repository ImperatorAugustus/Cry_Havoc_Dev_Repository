(define "handle_ik"
	{on ik begin "basis"				;// basis bone rotates
		{play_sound "basis_turret" 1}
	}
	{on ik end "basis"					;// basis stops rotation
		{stop_sound "basis_turret"}
	}
	{on ik begin "turret"				;// turret bone rotates (horizontal rotation)
		{if cannon_state "fire"
			{play_sound "rotate_turret" 1}
			{ani_play "aim_h" loop resume}
		}
	}
	{on ik end "turret"					;// turret stops rotation
		{stop_sound "rotate_turret"}
		{ani_stop "aim_h"}
	}
	{on ik begin "gun_rot"				;// gun bone rotates (vertical rotation)
		{if cannon_state "fire"
			{play_sound "rotate_gun" 1}
			{ani_play "aim_v" loop resume}
		}
	}
	{on ik end "gun_rot"				;// gun stops rotation
		{stop_sound "rotate_gun"}
		{ani_stop "aim_v"}
	}
)

;/*=========== Cannon Begin ===========*/

{"cannon"							;// master / base code for all cannons
	("handle_ik")

	{on animation_end "close"		;// stops rotation sound when cannon switchs to closed state
		{tags add "test"} 			;//test (delete when working)
		{stop_sound "rotate_turret"}
		{ani_stop "aim_h"}
	}

	{on "gun_pebble_start"			;// special event called during mission script
		{add_view "gun_broken" "gun_broken" "foresight1"}
		{view start "gun_broken"}
	}

	{on "gun_pebble_stop"			;// special event called during mission script
		{view stop "gun_broken"}
	}

	{on spawn
		{set "engine_on" 0}
	}

	{on move on overload
		{play_sound "move" 1}
	}

	{on turn on overload
		{play_sound "move" 1}
	}

	{on turn off
		{stop_sound "move"}
	}

	{on move off
		{stop_sound "move"}
	}

	{on "add_movement_sound"
		{link_sound "move" "vehicle/cannon_roll"}
	}

	{on pierce sync
		{vehicle_health_damage_pierce}
	}

	(define "impluse_process_blast" 				;// {on blast_hit} blastwave hits any part of entity
		{if min_energy %blast_energy
			{if not linked			;// cannon linked to another vehicle (ex. being towed). Otherwise, impulse will break the link.
				{impulse up (/ %impulse 3) (/ %range 2) dir (/ %impulse 2) %range}
			}
			{if simulating			;// simulating: entity is being handled by physics right now. i.e. being thrown by impulse
				{attack_save}		;// saves attacker information (attacker entity/weapon)
				{delay_ex 0.1
					{attack_load}		;// loads attacker information (attacker entity/weapon)
					;//{crew_throw_off up 2 1 dir 5 1 turn 0 180 forward 1 force} ;// disabled as crew can be thrown of by direct blast to individuals
				}
			}
		}
	)

	{on blast_hit					;// any part of vehicle hit with blast energy
		{if min_mass 100000				;// if mass ≥ 6000 kg			;// Super Heavy Cannons
			; do nothing

		else min_mass 6000				;// if mass ≥ 6000 kg			;// Super Heavy Cannons
			("impluse_process_blast"	blast_energy(9)					;// 150 HE and Up, Dynamite, Air Bombs
				impulse(3.0)			;// impulse amount
				range(0.25)				;// ± to impulse amount
			)
			("impluse_process_blast"	blast_energy(7)					;// 100mm HE - 130mm HE
				impulse(2.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(5)					;// 85mm HE - 93mm HE, AT Mine, 12cm Mortar
				impulse(1.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(3.5)				;// 75mm HE - 77mm HE
				impulse(1.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(2)					;// 37mm HE - 65mm HE, 8cm Mortar, RPG's
				impulse(0.5)
				range(0.25)
			)

		else min_mass 2250	;// if mass ≥ 2,250 kg						;// Heavy Cannons
			("impluse_process_blast"	blast_energy(9)					;// 150 HE and Up, Dynamite, Air Bombs
				impulse(3.5)			;// impulse amount
				range(0.25)				;// ± to impulse amount
			)
			("impluse_process_blast"	blast_energy(7)					;// 100mm HE - 130mm HE
				impulse(2.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(5)					;// 85mm HE - 93mm HE, AT Mine, 12cm Mortar
				impulse(2.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(3.5)				;// 75mm HE - 77mm HE
				impulse(1.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(2)					;// 37mm HE - 65mm HE, 8cm Mortar, RPG's
				impulse(1.0)
				range(0.25)
			)

		else min_mass 800	;// if mass ≥ 800 kg						;// Small Medium Cannons
			("impluse_process_blast"	blast_energy(9)					;// 150 HE and Up, Dynamite, Air Bombs
				impulse(4.0)			;// impulse amount
				range(0.25)				;// ± to impulse amount
			)
			("impluse_process_blast"	blast_energy(7)					;// 100mm HE - 130mm HE
				impulse(3.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(5)					;// 85mm HE - 93mm HE, AT Mine, 12cm Mortar
				impulse(2.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(3.5)				;// 75mm HE - 77mm HE
				impulse(2.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(2)					;// 37mm HE - 65mm HE, 8cm Mortar, RPG's
				impulse(1.5)
				range(0.25)
			)

		else min_mass 300	;// if mass ≥ 300 kg						;// Light Cannons
			("impluse_process_blast"	blast_energy(9)					;// 150 HE and Up, Dynamite, Air Bombs
				impulse(4.5)			;// impulse amount
				range(0.25)				;// ± to impulse amount
			)
			("impluse_process_blast"	blast_energy(7)					;// 100mm HE - 130mm HE
				impulse(3.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(5)					;// 85mm HE - 93mm HE, AT Mine, 12cm Mortar
				impulse(3.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(3.5)				;// 75mm HE - 77mm HE
				impulse(2.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(2)					;// 37mm HE - 65mm HE, 8cm Mortar, RPG's
				impulse(2.0)
				range(0.25)
			)

		else				;// if mass less than 300 kg				;// Carried Cannons
			("impluse_process_blast"	blast_energy(9)					;// 150 HE and Up, Dynamite, Air Bombs
				impulse(5.0)			;// impulse amount
				range(0.25)				;// ± to impulse amount
			)
			("impluse_process_blast"	blast_energy(7)					;// 100mm HE - 130mm HE
				impulse(4.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(5)					;// 85mm HE - 93mm HE, AT Mine, 12cm Mortar
				impulse(3.5)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(3.5)				;// 75mm HE - 77mm HE
				impulse(3.0)
				range(0.25)
			)
			("impluse_process_blast"	blast_energy(2)					;// 37mm HE - 65mm HE, 8cm Mortar, RPG's
				impulse(2.5)
				range(0.25)
			)
		}
	}

	{on "cut_parts"
		{add_view "smoke_dead_norm" "deathfx" "fxfire1"}
		{view start "deathfx"}
		{if tagged "leave_unit"
			{call "self_destruct"}
		}
		(define "cut_part"
			{if rand %1
				{if "crush"
					{tear "piece_medium_steel" bone %0
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}
						{call "check_delete_part"}
					}
				else
					{tear "piece_medium_steel" bone %0
						{impulse up 4 1 dir 4 2 cx 2 1 cy 2 1 rnd_dir 4 no_position}
						{call "check_delete_part"}
					}
				}
			}
		)
		("cut_part" args "standL" 1)
		("cut_part" args "standL1" 1)
		("cut_part" args "standL2" 1)
		("cut_part" args "standR" 1)
		("cut_part" args "standR1" 1)
		("cut_part" args "standR2" 1)
		("cut_part" args "shield_lower" 1)
		("cut_part" args "part1" 0.6)
		("cut_part" args "part2" 0.6)
		("cut_part" args "part3" 0.6)
		("cut_part" args "part4" 0.6)
		("cut_part" args "part5" 0.6)
		("cut_part" args "part6" 0.6)
		("cut_part" args "part7" 0.6)
		("cut_part" args "part8" 0.6)
		("cut_part" args "part9" 0.6)
		("cut_part" args "wheelL" 0.6)
		("cut_part" args "wheelR" 0.6)
		("cut_part" args "wheelL1" 0.6)
		("cut_part" args "wheelR1" 0.6)
		("cut_part" args "wheelL2" 0.6)
		("cut_part" args "wheelR2" 0.6)
		("cut_part" args "wheelleft" 0.6)
		("cut_part" args "wheelleft1" 0.6)
		("cut_part" args "wheelleft2" 0.6)
		("cut_part" args "wheelright" 0.6)
		("cut_part" args "wheelright1" 0.6)
		("cut_part" args "wheelright2" 0.6)
		("cut_part" args "fragment1" 1)
		("cut_part" args "fragment2" 1)
		("cut_part" args "fragment3" 1)
		("cut_part" args "fragment4" 1)
		("cut_part" args "fragment5" 1)
		{delay 14 {view stop "deathfx"}}
	}

	{on fire "gun"
		{ani_play "recoil"}
		{view start "flashbarrel1"}
		{view start "flashbarrel1smoke"}
		{call "spawn_shell"}
	}

	{on "spawn_shell"
		{tags add "gun_fired"}
		{call "spawn_shell_delay"}
		(define "shell_eject_delay"
			{delay_ex %0
				{ani_play "shell_eject" 1.0}
				{delay_ex %1
					{add_view "smoke_breach" "smoke_shell" "fx_invers"}
					{view start "smoke_shell"}
					{delay 2.5 0.5
						{view stop "smoke_shell"}
					}
					{spawn "shell_cannon" "fx_invers" x scale 0.014
						{impulse forward 4 0.5 rnd_dir 0.1 0.1 cz 0.2 0.1 com}
						{add_view "smoke_empty_shell" "smoke_shell" "fx_shellsmoke"}
						{view start "smoke_shell"}
						{delay_effect 3 1 "stop"}
					}
				}
			}
		)
	}

	{on "spawn_shell_delay"
		("shell_eject_delay" args 0.15 0.05)
	}

	{on "reload"
		{call "reload_delay"}
		{call "crew_reload_ani"}
		(define "reload_time"
			{if tagged "gun_fired"
				{delay (- %0 0.5) ;4.5
					{tags remove "gun_fired"}
					{call "cannon_reloaded"}
				}
			else ;//switching ammo
				{delay 0.75
					{ani_play "shell_eject" 1.0}
					{talk "reload"}
				}
				{delay (- %0 0.5)
					{call "cannon_reloaded"}
				}
			}
		)
		{delay 2
			{talk "reload"}
		}
	}

	{on "cannon_reloaded"
		{ani_play "shell_eject" -1.0}
		{delay 0.5
			{talk "reloaded"}
		}
	}

	{on "reload_delay"
		("reload_time" args 4.5)		;// weapon reload time
	}

	{on contact
		{if not impregnable
			{if not effector "bicycle"
				{if not effector "armored_car"
					{if effector "tank"
						{call "crush_damage_tank"}
					else effector "train" ;// or "railway"
						{call "crush_damage"}
					else effector "airborne"
						{call "crush_damage"}
					else effector "grenade"
						{if not effector "mine"
							{talk "grenade"}
							{crew_emit}
						}
					}
				}
				{if effector "vehicle"
					{if effector_velocity 2
						{call_synced "contact_fx_sync"}
					}
				}
			}
		}
	}

	{on "contact_fx_sync"
		{if not "fx_delay"
			{set "fx_delay" 1}
			{delay 2 "fx_delay"
				{set "fx_delay" 0}
			}
			{call "contact_fx"}
		}
	}

	{on "crush_damage_tank"
		{if effector_velocity 10
			{call_synced "crush_destroy_sync"}
		else effector_velocity 5
			{component break}
		}
	}
	{on "crush_destroy_sync"
		{crew_emit}
		{set "crush" 1}
		{call "explosion"}
		{call "stat_break"}
	}
	{on "crush_damage"
		{if effector_velocity 6
			{call_synced "crush_break_sync"}
		}
	}
	{on "crush_break_sync"
		{crew_emit}
		{set "crush" 1}
		{component break}
	}
	{on "contact_fx"
		{spawn "metal_crush" "root"}
	}

	{on "check_water_level" overload
		{if not linked
			{if water_level 1.3
				{able "sinking" 1}
				{tags add "no_scavenge"}
			else
				{able "sinking" 0}
			}
		}
	}

	{on "sandbag_cannon"
		{link_sound "deploy" "vehicle/deploy"}
		{play_sound "deploy"}
		{spawn "placement_sandbag_generic" "basis" x}
	}

	{on "tear_wheel" overload} ;// disables wheels from being torn on cannons

	{on "emit_crew"
		{crew_emit}
	}

	{on "self_destruct"
		{spawn "car_die" "basis"}
	}
	{on destroy
		{if component "body"
			{if not "crush"
				{call "self_destruct"}
			}
		}
	}
}

;/*=========== Cannon End ===========*/

;/*=========== General Props Begin ===========*/

{"cannon no_shell"
	{on "spawn_shell" overload
		{tags add "gun_fired"}
		{call "no_spawn_shell_delay"}
		(define "no_shell_eject_delay"
			{delay_ex %0
				{ani_play "shell_eject" 1.0}
				{delay_ex %1
					{add_view "smoke_breach" "smoke_shell" "fx_invers"}
					{view start "smoke_shell"}
					{delay 2.5 0.5
						{view stop "smoke_shell"}
					}
				}
			}
		)
	}
	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 0.15 0.05)
	}
}


{"cannon wheeled"
	{on "check_work_mover" overload			;// overrides wheel settings in car interaction scripts
		{if tagged "wheel_teared"
			{chassis_work 0}
		else
			{if broken "wheel" 2			;// 2 broken wheels
				{movement_limit slow}
				{chassis_work 1}
			else broken "wheel" 1			;// 1 broken wheel
				{movement_limit normal}
				{chassis_work 1}
			else not broken "wheel"			;// 0 broken wheels
				{chassis_work 1}
				{movement_limit fast}
			}
		}
	}
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
}

{"cannon tracked"
	{on "check_work_mover" overload			;// overrides wheel settings in car interaction scripts
		{if work "mover"
			{if not tagged "wheel_destroyed"		;// Checks if wheel has been torn off
				{if not tagged "engine_turned_off"	;// Checks that player didn't turn off engine before repairs are made
					{chassis_work 1}
					{ik_enable "basis" 1}	;// allows motorized cannons to rotate when engine or track is broken
				}
			}
		else
			{chassis_work 0}
			{ik_enable "basis" 0}			;// stops motorized cannons from rotating when engine or track is broken
		}
	}
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
}

{"cannon wheeled invisible"			;// disables and enables wheel volumes for those cannons that hide their wheels when in "fire" state.
	{on spawn
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}
	{on animation_event "close"		;// event called on frame 0 of "close" animation
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}
	{on "show_wheels"				;// ables for all wheel volumes
		{volumes "invisible" enable visible bullet blast contact contact_ground select obstacle touch NoWoundDecal}
	}
	{on "hide_wheels"				;// removes ables for all wheel volumes
		{volumes "invisible" disable all}
		{volumes "invisible" enable contact_ground}
	}
	{on "cut_parts"					;// when cannon is destroyed and wheels/trailer are hidden
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}
}

{"cannon motorized"			;// disables and enables engine for those cannons that motorized and toggle when in "fire" state.
	{on animation_event "close"		;// event called on frame 0 of "close" animation
		{if cannon_state "fire"
			{call "engine_off"}
			{tags remove "state_close"}
		else
			{tags add "state_close"}
			{if not "engine_on"
				{if not "toggle_delay"
					{call "engine_on"}
				}
			}
		}
	}

	{on "chassis_off" overload}			;// disables the chassis_work 0 so cannon can still be ordered to move when is fire state

	{on "repaired_engine_check" overload 	;// turns engine on when repaired if crewed and not tagged engine off
		{if not "engine_check" 				;// stops call from happening at spawn
			{if tagged "state_close"		;// check for motorized cannons
				{if operatable
					{if not tagged "engine_turned_off"
						{if not "engine_on"
							{call "engine_on"}
						}
					}
				}
			}
		}
	}
}

{"cannon ammo_crate"
	{##on animation_event "close"		;// event called on frame 0 of "close" animation
		{if cannon_state "fire"
			{crew_emit}
		}
	}
}


{"cannon bunker"
	{inflammation_time 30}
	{on spawn
		{link_sound "burn_small" "fire/loops/medium"}
	}

	{on blast_hit overload}
	{on contact overload
		{if not impregnable
			{if not effector "bicycle"
				{if effector "vehicle"
					{if effector_velocity 2
						{if not "fx_delay"
							{set "fx_delay" 1}
							{delay 2 "fx_delay"
								{set "fx_delay" 0}
							}
							{spawn "metal_crush" "root"}
						}
					}
				}
			}
		}
	}
	{on break overload
		{if not tagged "exploded"
			{if component "body"
				{view stop "ammo"}
				{call "stat_break"}
				{call "kill_gunner"}
				{call "kill_commander"}
				{call "deactivate_vehicle"}
				{start_sound "crush/medium/metal"}
				{spawn "tank_die_particle" "body"}
				{crew_emit}
				{able select 0}			;// disables vehicle from being crewed until body is repaired
			}
			{if component "wheel"
				{if not linked
					{if not velocity 0.5
						{call "break_wheel_impulse"}
					}
				}
			}
		}
	}
	{on repair
		{if component "body"
			{able "select" 1}
		}
	}

	(define "kill_crew"			;// general code for killing crew on peirce and blast events
		{on "kill_%0"
			{if crew_in_place "%0"
				{kill_crew "%0"}
				{delay 0.2
					{damage_report "%0" "component/%0_die"}
					{talk "crew_die"}
				}
			}
		}
	)
	("kill_crew" args commander)
	("kill_crew" args gunner)

	{on "impulse" overload
		{if not cannon_state "fire"
			{physics_work 1}
			{impulse up 0.01}
		}
	}
	
	{on "show_wheels"				;// ables for all wheel volumes
		{physics_work 1}
	}
	{on "hide_wheels"
		{physics_work 0}
	}

	{on "_burn" overload
		{if not tagged "burned"
			{if not able "exploded"
				{talk "burning"}
				{call "check_burn_emit"}

				{if not tagged "burning"
					{burn volume fx "smoke_dead_tree1" time 20 fake even_law}
					{add_view "smoke_dead_norm" "burn_fire" "basis"}
					{add_view "smoke_engine" "burn_fire_smoke" "basis"}
					{view start "burn_fire"}
					{play_sound "burn_small" 1}
					{tags add "burning"}
					{fire radius 2 time 20 heating 2}
					{set "burn_fire" 1}
					{delay 6
						{components "body" break}
					}
				}
				{delay 20
					{view start "burn_fire_smoke"}
					{view stop "burn_fire"}
					{stop_sound "burn_small"}
					{tags remove "burning"}
					{set "burn_fire" 0}
					{able "burning" 0}
					{delay 30
						{view stop "burn_fire_smoke"}
					}
				}
			}
		}
	}

	{on "burn_volume"
		{if not burned
			{if volume "body"
				{call "_burn"}
			}
		else
			{tags add "already_burned"}
		}
	}

	{on "check_burn_emit"
		{call "burn_emit"}
	}
}

{"with_gun automatic"
	{on "spawn_shell" overload
		{call "spawn_shell_delay_auto"}
		(define "shell_eject_delay_auto"
			{delay_ex %0
				{spawn "shell_cannon_auto" "fx_invers" x scale 0.014
					{impulse forward 2.5 0.25 up 0.4 0.2 fx 0.7 0.2 cx -1 com}
				}
			}
		)
	}
	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0)
	}
	{on "reload" overload
		{call "magazine_delay"}
		{call "crew_reload_ani"}
	}
	(define "magazine"
		{on "magazine_delay" %override
			{delay %cut
				{tear "piece_small_steel" bone "magazine" copy
					%impulse
				}
				{delay 0
					{view hide "magazine"}
					{delay %show
						{view show "magazine"}
					}
				}
			}
		}
	)
	("magazine" cut(0) show(1.8) override() impulse({impulse up -0.01 com}))
	{on fire "gun"
		{if not tagged "full_auto_mode"
			{call "burst_stop"}
		}
	}
	
	{on "burst_mode"
		{if tagged "full_auto_mode"
			{tags remove "full_auto_mode"}
			{damage_report "mgun" "Unit changed to burst mode"}
		else
			{tags add "full_auto_mode"}
			{damage_report "mgun" "Unit changed to full auto mode"}
		}
	}
	
	{on "burst_stop"
		{if not tagged "burst_stop"
			{tags add "burst_stop"}
			{delay 0.5 0.2
				{weapon_work "gun" 0}
				{delay 0.7 0.1
					{weapon_work "gun" 1}
					{tags remove "burst_stop"}
				}
			}
		}
	}
}

{"cannon magazine"
	{on "reload"
		{call "magazine_delay"}
	}
	(define "magazine"
		{on "magazine_delay" %override
			{delay %cut
				{tear "piece_small_steel" bone "magazine" copy
					%impulse
				}
				{delay 0
					{view hide "magazine"}
					{delay %show
						{view show "magazine"}
						{delay 1
							{ani_play "bolt" 1.0}
						}
					}
				}
			}
		}
	)
	("magazine" cut(0) show(1.8) override() impulse({impulse up -0.01 com}))
	{on fire "gun"
		{if not tagged "full_auto_mode"
			{call "burst_stop"}
		}
	}
	
	{on "burst_mode"
		{if tagged "full_auto_mode"
			{tags remove "full_auto_mode"}
			{damage_report "mgun" "Unit changed to burst mode"}
		else
			{tags add "full_auto_mode"}
			{damage_report "mgun" "Unit changed to full auto mode"}
		}
	}
	
	{on "burst_stop"
		{if not tagged "burst_stop"
			{tags add "burst_stop"}
			{delay 0.5 0.2
				{weapon_work "gun" 0}
				{delay 0.7 0.1
					{weapon_work "gun" 1}
					{tags remove "burst_stop"}
				}
			}
		}
	}
}

{"cannon_small"					;// allows cannon to be crushed by armored cars, when normally they cannot.
	{on contact
		{if not impregnable
			{if effector "armored_car"
				{call "crush_damage"}
			else effector "truck"
				;// do nothing
			else effector "car"
				;// do nothing
			}
		}
	}
	{on "crush_damage" overload
		{if effector_velocity 10
			{call_synced "crush_destroy_sync"}
		else effector_velocity 5
			{component break}
		}
	}

	{on blast_hit
		{if min_energy 3.15
			{call "explosion"}
			{component destroy}
			{call "stat_break"}
		}
	}
}

{"carried"			;// applies footstep sounds instead of wheeled sounds to cannon movement
	{on "add_movement_sound" overload
		{link_sound "move" "human/move/run/ground"}
	}
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
}

{"cannon sled"		;// applies dragging sounds instead of wheeled sounds to cannon movement
	{on "add_movement_sound" overload
		{link_sound "move" ""}
	}
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
}

{"cannon fixed"
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
}

{"mg_stan"			;// assigned to poperties/cannon_mgun.ext. Special code for machine gun class cannons.
	{on spawn
		{add_view "flash_gun_big" "flashbarrel" "foresight14"}
	}
	{on fire "mgun"
		;{view start "flashbarrel"}
		{ani_play "recoil"}
		{if not tagged "full_auto_mode"
			{call "burst_stop"}
		}
	}
	{on fire "mgun1"
		;{view start "flashbarrel"}
		{ani_play "recoil"}
		{if not tagged "full_auto_mode"
			{call "burst_stop"}
		}
	}
	{on "explosion_blastwave" overload}

	{on "self_destruct" overload
		{spawn "ex_air_small" "basis"}
	}

	{on "cut_parts" overload			;// Forces Mortars to cut all parts instead of using random chance.
		("cut_part" args "part1" 1)		;// Looks odd when legs cut but barrel floats in air.
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}
	{on contact
		{if not impregnable
			{if  effector "truck"
				{call "crush_damage"}
			else effector "car"
				{call "crush_damage"}
			}
		}
	}
	{on "burst_mode"
		{if tagged "full_auto_mode"
			{tags remove "full_auto_mode"}
			{damage_report "mgun" "Unit changed to burst mode"}
		else
			{tags add "full_auto_mode"}
			{damage_report "mgun" "Unit changed to full auto mode"}
		}
	}
	
	{on "burst_stop"
		{if not tagged "burst_stop"
			{tags add "burst_stop"}
			{delay 0.5 0.2
				{weapon_work "gun" 0}
				{delay 0.7 0.1
					{weapon_work "gun" 1}
					{tags remove "burst_stop"}
				}
			}
		}
	}
}

{"no_exp_blast"		;// disables blastwave damage and sound when vehicle is crushed or explodes.
	{on "explosion_blastwave" overload}
	{on "explosion_sound" overload}
	{on "self_destruct" overload
		{spawn "ex_air_small" "basis"}
	}
}

{"mortar"			;// code unique to mortar class cannons
	{on spawn
		{add_view "flash_cannon_small" "flashbarrel1" "foresight"}
		{link_sound "whistle" "weapon/shot/mortar/whistle"}
		{link_sound "bkg_mortar" "weapon/shot/bkg/mortar/"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{view start "flashbarrel1"}
		{call "minimum_terrain_fx"}
		{play_sound "bkg_mortar"}
		{delay 1.5
			{play_sound "whistle"}
		}
		{delay 2
			{view pause "flashbarrel1"}
		}
		{call "crew_fire_ani"}
	}
	{on contact
		{if not impregnable
			{if effector "truck"
				{call "crush_damage"}
			else effector "car"
				{call "crush_damage"}
			}
		}
	}
}

{"mortar cannon"
	{on "cut_parts" overload			;// Forces Mortars to cut all parts instead of using random chance.
		("cut_part" args "part1" 1)		;// Looks odd when legs cut but barrel floats in air.
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_curved_heap" "sandbag")
	}

	{on "self_destruct" overload
		{spawn "ex_air_small" "basis"}
	}
}

{"flak"				;// base code for multi-barrel cannons and vehicles. To customize, add unique code to specific cannon name prop
	("handle_ik")
	{on "init_gun"
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel00"	"shooter00"}
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel01"	"shooter01"}
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel02"	"shooter02"}
		{add_view "tank_canon_fire_20_25_auto"			"flashbarrel03"	"shooter03"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "smoke_zenit"			"smoke02"		"shooter02"}
		{add_view "smoke_zenit"			"smoke03"		"shooter03"}
		{add_view "zenit_gilz"			"shell"			"FXshell1"}
		{add_view "zenit_gilz"			"shell"			"FXshell2"}
		{add_view "zenit_gilz"			"shell"			"FXshell3"}
		{add_view "zenit_gilz"			"shell"			"FXshell4"}
		{call "update_gun"}
	}
	{on "add_movement_sound"
		{link_sound "rotate_turret" "vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_gun" "vehicle/turret/gun/gun_vertical"}
	}
	{on fire "gun" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{play_sound "bkg_auto"}
				{ani_play "fire%0"}
				{delay 0.12
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)
		{if	("fire_barrel" args 00)
		else ("fire_barrel" args 01)
		else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		}
		{if name "00"
			{call "fire_gun_common"}
		}
		{ani_play "recoil"}
		{call "spawn_shell"}
		{if not tagged "full_auto_mode"
			{call "burst_stop"}
		}
	}
	{on "fire_gun_common"
		{view start "flashbarrel"}
		;{ani_play "recoil"}
		{kill_delay "shell_off"}
		{view start "shell"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
		}
		{if not tagged "full_auto_mode"
			{call "burst_stop"}
		}
	}
	
	{on "burst_mode"
		{if tagged "full_auto_mode"
			{tags remove "full_auto_mode"}
			{damage_report "mgun" "Unit changed to burst mode"}
		else
			{tags add "full_auto_mode"}
			{damage_report "mgun" "Unit changed to full auto mode"}
		}
	}
	
	{on "burst_stop"
		{if not tagged "burst_stop"
			{tags add "burst_stop"}
			{delay 0.5 0.2
				{weapon_work "gun" 0}
				{delay 0.7 0.1
					{weapon_work "gun" 1}
					{tags remove "burst_stop"}
				}
			}
		}
	}
}

{"burst"
	{on fire "gun"
		{if not tagged "full_auto_mode"
			{call "burst_stop"}
		}
	}
	
	{on "burst_mode"
		{if tagged "full_auto_mode"
			{tags remove "full_auto_mode"}
			{damage_report "mgun" "Unit changed to burst mode"}
		else
			{tags add "full_auto_mode"}
			{damage_report "mgun" "Unit changed to full auto mode"}
		}
	}
	
	{on "burst_stop"
		{if not tagged "burst_stop"
			{tags add "burst_stop"}
			{delay 0.5 0.2
				{weapon_work "gun" 0}
				{delay 0.7 0.1
					{weapon_work "gun" 1}
					{tags remove "burst_stop"}
				}
			}
		}
	}
}

{"nebelwerfer"			;// code for the nebelwerfer rocket vehicles
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"	"foresight"}
		{add_view	"dust_nebelfire"		"dust"			"turret"}
		{add_view	"dust_nebelfire_snow"	"snow"			"turret"}
		{link_sound "bkg_rocket" "weapon/shot/bkg/rocket/"}
	}
	{on fire "gun" overload
		{ani_play "recoil"}
		{play_sound "bkg_rocket"}
		{view start "flashbarrel1"}
		{delay 2
			{view pause "flashbarrel1"}
		}
		(define "nebelwerfer_fire"
			{if terrain_fx "snow"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "ice"
				{view start "snow"}
				{delay 0.3 {view pause "snow"}}
			else terrain_fx "shallow_water"
				;nothing
			else
				{view start "dust"}
				{delay 0.3 {view pause "dust"}}
			}
		)
		{if name "00"
			("nebelwerfer_fire")
		else name "01"
			("nebelwerfer_fire")
		else name "02"
			("nebelwerfer_fire")
		else name "03"
			("nebelwerfer_fire")
		else name "04"
			("nebelwerfer_fire")
		else name "05"
			("nebelwerfer_fire")
		else name "06"
			("nebelwerfer_fire")
		else name "07"
			("nebelwerfer_fire")
		else name "08"
			("nebelwerfer_fire")
		else name "09"
			("nebelwerfer_fire")
		}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
}

{"recoilless"
	{on spawn
		{add_view   "recoilless_shot"			"flashbarrelsmall"	"fxshot"}
		{add_view	"recoilless_shot_forward"	"flashbarrel1"		"foresight1"}
		{add_view	"dust_recoilless"			"dust"				"turret"}
		{add_view	"dust_recoilless_snow"		"snow"				"turret"}
		{link_sound "bkg_cannon_medium" "weapon/shot/bkg/cannon/medium/"}
	}
	{on fire "gun"
		{play_sound "bkg_cannon_medium"}
		{view start "flashbarrelsmall"}
		;{spawn "tank_canon_fire_50_57"	"fxshot" x}
		;{spawn "bazooka_shot"	"foresight1" x}
		{if terrain_fx "snow"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "ice"
			{view start "snow"}
			{delay 0.3 {view pause "snow"}}
		else terrain_fx "shallow_water"
			;nothing
		else
			{view start "dust"}
			{delay 0.3 {view pause "dust"}}
		}
	}
}

{"searchlight"			;// code for searchlight vehicles
	{on spawn
		{add_view "light_searchlight" "lights" "lamp_light_spot1"}
		{view hide "lights"}
	}

	{on "update_lights" overload
		{if operatable
			{if cannon_state "fire"
				{if work "gun"
					{call "lights_on"}
				else
					{call "lights_off"}
				}
			else
				{call "lights_off"}
			}
		else
			{call "lights_off"}
		}
	}

	{on animation_event "close"		;// event called on frame 0 of "close" animation
		{call "update_lights"}
	}

	{on break
		{if component "lamp"
			{call "break_lamp"}
		}
		{if component "gun"
			{call "update_lights"}
			{crew_emit}
			{crew_enable place "gunner" 0}
			{components "lamp" break}
			{call "break_lamp"}
		}
	}
	{on repair
		{if component "gun"
			{call "update_lights"}
			{crew_enable place "gunner" 1}
			{components "lamp" repair}
		}
		{if component "lamp"
			{restore_volume_states} ; restore volume ables from .def file
		}
	}

	{on ground_hit sync
		{call "explosion"}
	}
	{on "_explosion"
		{drop_orders}
	}
	{on operatable on
		{call "update_lights"}
	}
	{on operatable off
		{call "update_lights"}
	}
}

{"ammo_crate wood"
	{on break overload											;// {on break ... is for when components break.
		{crew_emit}
		{if component "body"
			{call "break"}
		}
	}

	{on contact
		{if not impregnable
			{if  effector "truck"
				{call "crush_damage"}
			else effector "car"
				{call "crush_damage"}
			}
		}
	}

	{on "crush_damage_tank" overload
		{if effector_velocity 5
			{call_synced "crush_break_sync"}
		}
	}

	{on "crush_damage" overload
		{if effector_velocity 1
			{call_synced "crush_break_sync"}
		}
	}

	{on "break"
		{call "stat_break"}
		{if not "crush"
			{call "explosion"}
		}
		{call "crush_fx"}
		{delay 0.05 {delete}}
	}

	{on "contact_fx" overload
		{spawn "wood_hit_piece" "root"}
	}

	{on "crush_fx"
		{spawn "wood_hit_br" "root"}							;// dust fx
		{call "destroyed_stamp"}
	}
	{on "destroyed_stamp" overload
		{spawn "crash_wood" no_position random_orientation}		;// stamp
	}
	{on "explosion_blastwave" overload
		{blastwave c4 10 r0 4.0 r1 10}
		{spawn "ammo_crate_die" "basis"}
	}
}

{"stretcher_vehicle"
	{on break overload											;// {on break ... is for when components break.
		{crew_emit}
		{if component "body"
			{call "break"}
		}
	}
	
	{on contact
		{if not impregnable
			{if  effector "truck"
				{call "crush_damage"}
			else effector "car"
				{call "crush_damage"}
			}
		}
	}

	{on "crush_damage_tank" overload
		{if effector_velocity 5
			{call_synced "crush_break_sync"}
		}
	}

	{on "crush_damage" overload
		{if effector_velocity 1
			{call_synced "crush_break_sync"}
		}
	}

	{on "break"
		{call "stat_break"}
		{if not "crush"
			{call "explosion"}
		}
		{call "crush_fx"}
		{delay 0.05 {delete}}
	}

	{on "contact_fx" overload
		{spawn "wood_hit_piece" "root"}
	}

	{on "crush_fx"
		{spawn "wood_hit_br" "root"}							;// dust fx
		{call "destroyed_stamp"}
	}
	{on "destroyed_stamp" overload
		{spawn "crash_wood" no_position random_orientation}		;// stamp
		{spawn "ground_blood_big" no_position random_orientation}		;// stamp
		{spawn "bloodstain" no_position random_orientation}		;// stamp
	}
}
;/*=========== General Props End ===========*/

;/*=========== Specific Cannons Begin ===========*/

;/*=========== Soviets Begin ===========*/

{"broneschitok"
	{on "check_water_level" overload
		{if not linked
			{if water_level 1.0
				{able "sinking" 1}
				{tags add "no_scavenge"}
			else
				{able "sinking" 0}
			}
		}
	}
}

{"mg_stan wheeled"
	{on "add_movement_sound" overload
		{link_sound "move" "vehicle/cannon_roll/metal_wood"}
	}
}

{"maxim_"
	{on "add_weapon_sound"
		("Maxim_Gun")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
	}
	{on "init_gun"
		{add_view "shell_mgun" "shell" "FXshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}
	{on fire "mgun1"
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{play_sound "action_recoil"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view pause "flashbarrel"}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
}

{"maxim_stand"
	{on "break_wheel_impulse" overload}		;// Disables broken wheel impulse.

	{on "add_movement_sound" overload
		{link_sound "move" "vehicle/cannon_roll/metal_wood"}
	}
}

{"maxim_x4"
	{on "init_gun" overload
		{add_view "shell_mgun" "shell1" "fxshell1"}
		{add_view "shell_mgun" "shell2" "fxshell2"}
		{add_view "shell_mgun" "shell3" "fxshell3"}
		{add_view "shell_mgun" "shell4" "fxshell4"}
		{add_view "ejectsmoke_big" "ejectsmoke1" "FXshell1"}
		{add_view "ejectsmoke_big" "ejectsmoke2" "FXshell2"}
		{add_view "ejectsmoke_big" "ejectsmoke3" "FXshell3"}
		{add_view "ejectsmoke_big" "ejectsmoke4" "FXshell4"}
		{add_view "flash_gun_big" "flashbarrel00" "shooter00"}
		{add_view "flash_gun_big" "flashbarrel01" "shooter01"}
		{add_view "flash_gun_big" "flashbarrel02" "shooter02"}
		{add_view "flash_gun_big" "flashbarrel03" "shooter03"}
	}
	{on fire "mgun1" overload
		(define "fire_barrel"
			name "%0"
				{call "fire_barrel%0"}
				{view start "flashbarrel%0"}
				{delay 0.2 "fire"
					{view pause "flashbarrel%0"}
				}
				{play_sound "MG_Mid"}
				{play_sound "MG_Far"}
				{play_sound "action_recoil"}
				{kill_delay "shell_off%1"}
				{view start "shell%1"}
				{view start "ejectsmoke%1"}
				{delay 0.12 "shell_off%1"
					{view pause "shell%1"}
					{view pause "ejectsmoke%1"}
				}
		)
		{if	("fire_barrel" args 00 1)
		else ("fire_barrel" args 01 2)
		else ("fire_barrel" args 02 3)
		else ("fire_barrel" args 03 4)
		}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
}
{"ds39_stand"
	{on "add_weapon_sound" overload
		("DS39")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
	}
}
{"sg43_stand"
	{on "add_weapon_sound" overload
		("SG43")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
	}
}

{"dshk_aa"
	{on "init_gun" overload
		("DShK38")
		{add_view "shell_hmgun" "shell" "fxshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}

	{on fire "mgun1"
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{play_sound "action_recoil_HMG"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_straight_heap" "sandbag")
	}
}

{"dshk_stan"
	{on "init_gun" overload
		("DShK38")
		{add_view "shell_hmgun" "shell" "fxshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}

	{on fire "mgun1"
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{play_sound "action_recoil_HMG"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
}

{"25mm_72k"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.23) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_small")
}

{"37mm_61k"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.35) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}

	("cannon_small")
}

{"37mm_m30"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.05)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"45mm_m37"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"45mm_m42"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"57mm_zis2"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_small")
}

{"57mm_zis2_late"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_small")
}

{"76mm_bpk76"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.5)
	}

	("cannon_small")
}

{"76mm_m1902"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		{inherited}
	}

	("cannon_small")
}

{"76mm_m1927"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.5)
	}

	("cannon_small")
}

{"76mm_m43"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	("cannon_small")
}

{"76mm_m1933"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 8.5)
	}

	("cannon_small")
}

{"76mm_m1938"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 5.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

{"76mm_f22"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"76mm_zis3"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_small")
}

{"85mm_52k"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

{"100mm_bs3"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.9 0.15)
	}

	{on "reload_delay" overload
		("reload_time" args 6.1)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_big")
}

{"107mm_m1910_30"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}

{"122mm_m1910"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}

{"122mm_m30"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}
{"122mm_a19"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 18)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

{"152mm_ml20"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 23)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		{inherited}
	}

	("cannon_big")
}

{"d1"

}

{"152mm_br2"
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 12)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_big")
}

{"203mm_b4"
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 12)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_big")
}

{"280mm_br5"
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 12)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_big")
}

{"300mm_m30"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_curved_heap" "sandbag")
	}
}

{"300mm_m31"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_curved_heap" "sandbag")
	}
}

{"305mm_mb_2_12"
	{on spawn
		{add_view "tank_canon_fire_170_210"				"flashbarrel00"	"foresight1"}
		{add_view "tank_canon_fire_170_210"				"flashbarrel01"	"foresight2"}
		{add_view "tank_fire_maximum_dust_ground_rain"	"maximum_ground_r_fx"	"basis"}
		{add_view "tank_fire_maximum_dust_ground"		"maximum_ground_fx"		"basis"}
		{add_view "tank_fire_maximum_dust_sand_rain"	"maximum_sand_r_fx"		"basis"}
		{add_view "tank_fire_maximum_dust_sand"			"maximum_sand_fx"		"basis"}
		{add_view "tank_fire_maximum_dust_snow"			"maximum_snow_fx"		"basis"}
		{link_sound "bkg_cannon_huge" "weapon/shot/bkg/cannon/huge/"}
	}
	{on fire "gun1" overload
		{view start "flashbarrel00"}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "flashbarrel00"}
		{ani_play "fire00"}
		{start_sound "weapon/shot/tracer/"}
		{play_sound "bkg_cannon_huge"}
		{call "maximum_terrain_fx"}
	}
	{on fire "gun2" overload
		{view start "flashbarrel01"}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "flashbarrel01"}
		{ani_play "fire01"}
		{start_sound "weapon/shot/tracer/"}
		{play_sound "bkg_cannon_huge"}
		{call "maximum_terrain_fx"}
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		("cut_part" args "part7" 1)
		{spawn "vehicle_die" "basis"}
		{spawn "train_die" "basis"}
		{inherited}
	}
	
	{on break
		{if not tagged "exploded"
			{if component "gun1"
				{call "update_gun"}
				{tags add "gun1_brake"}
				{talk "broken_gun"}
			else component "gun2"
				{call "update_gun"}
				{tags add "gun2_brake"}
				{talk "broken_gun"}
			}
		}
	}
	{on repair
		{if component "gun1"
			{call "update_gun"}
			{tags remove "gun1_brake"}
		else component "gun2"
			{call "update_gun"}
			{tags remove "gun2_brake"}
		}
	}
	{on "update_gun"
		{if work "gun"
			{weapon_work "gun" 1}
		else
			{weapon_work "gun" 0}
		}
		{if work "gun1"
			{weapon_work "gun1" 1}
		else
			{weapon_work "gun1" 0}
		}
		{if work "gun2"
			{weapon_work "gun2" 1}
		else
			{weapon_work "gun2" 0}
		}
	}
}

{"ap2"
	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_big")
}

;/*=========== Soviets End ===========*/

;/*=========== Germans Begin ===========*/

{"mgun_ring"
	{on blast_hit overload}
	{on "gunner_hatch_open"
		{ani_play "mgun_aa" +1.0 resume}
	}
}

{"panzernest_krab"
	{on animation_event "close" overload		;// event called on frame 1 of "close" animation
		{if tagged "transition"
			{tags remove "transition"}
		else
			{tags add "transition"}
		}
		{call "body_check"}
	}

	{on animation_event "open"		;// event called on last frame of "close" animation
		{if tagged "transition"
			{tags remove "transition"}
		else
			{tags add "transition"}
		}
		{call "body_check"}
		
		{if cannon_state "fire"
			{call "hide_wheels"}
		else
			{call "show_wheels"}
		}
	}

	{on "body_check"				;// ables for all wheel volumes
		{if tagged "transition"
			{volumes "anim_no_contact" disable contact}
		else
			{volumes "anim_no_contact" enable contact}
		}
	}
	
	{on "cut_parts" overload
		("cut_part" args "wheelL" 1)
		("cut_part" args "wheelR" 1)
		{inherited}
	}
}

{"flak38"
	("cannon_small")
}

{"20mm_flak30"
	("magazine" cut(0.4) show(1.8) override(overload) impulse({impulse up 0.3 forward 0.9 0.1}))

	("cannon_small")
}

{"20mm_flak38"
	("magazine" cut(0.4) show(1.8) override(overload) impulse({impulse up 0.3 forward 0.9 0.1}))

	("cannon_small")
}

{"multi_sight"
	{on spawn
		("rand_cut_else" args "aim_sight1" "aim_sight2")
		("rand_cut_else" args "seat_1" "seat_2")
	}
}

{"37mm_flak37"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		("cut_part" args "part7" 1)
		{inherited}
	}

	("cannon_small")
}

{"28mm_pzb41"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 2.5)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_small")
}

{"37mm_pak36"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.05)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"47mm_pakt"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	("cannon_small")
}

{"50mm_flak41"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.32) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "standr" 1)
		("cut_part" args "standl" 1)
		("cut_part" args "trailer_front" 1)
		("cut_part" args "trailer_rear" 1)
		{inherited}
	}

	("cannon_big")
}

{"50mm_pak38"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part7" 1)
		{inherited}
	}

	("cannon_small")
}

{"50mm_kwk39_platform"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part7" 1)
		{inherited}
	}

	("cannon_small")
}

{"75mm_lg40"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.0 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	("cannon_small")
}

{"75mm_leig18"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.0)
	}

	("cannon_small")
}

{"75mm_legebig18"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}

	("cannon_small")
}

{"75mm_legebig18_snow"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.0)
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "wheelL" 1)
		{inherited}
	}

	("cannon_skis")
}


{"75mm_pak9738"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}

	("cannon_small")
}

{"75mm_pak40"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 5.25)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"88mm_flak18"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}
}

{"88mm_flak36"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")

	{on "cut_parts" overload
		("cut_part" args "part4" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}
}

{"88mm_pak4341"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.1 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 7.5)
	}

	("cannon_big")
}

{"105mm_lefh18"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 0.8)
		("cut_part" args "part2" 0.8)
		("cut_part" args "part3" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}

	("cannon_big")
}

{"105mm_lefh18m"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}
	{on "cut_parts" overload
		("cut_part" args "wheelr" 0.8)
		("cut_part" args "wheell" 0.8)
		("cut_part" args "standl" 1)
		("cut_part" args "standr" 1)
		("cut_part" args "part1" 1)
		{inherited}
	}

	("cannon_big")
}

{"105mm_sk18"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 23)
	}

	("cannon_big")
}

{"150mm_sig33"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.25)
	}

	{on "cut_parts" overload
		("cut_part" args "wheelr" 1)
		{inherited}
	}

	("cannon_big")
}

{"150mm_sfh18"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}

	("cannon_big")
}

{"150mm_nebelwerfer41"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	("cannon_small")

	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		{inherited}
	}
}

{"155mm_gpf_platform"
	{on blast_hit overload}
}

{"170mm_k18"
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 68)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_big")
}

{"210mm_nebelwerfer42"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	("cannon_small")

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		{inherited}
	}
}

{"210mm_morser18"
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 68)
	}
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_big")
}

{"600mm_thor"
	{on spawn
		{volumes "shell2" disable bullet blast}
	}
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload" overload
		{call "reload_delay"}
		{if tagged "gun_fired"
			{delay 12
				{tags remove "gun_fired"}
				{talk "reloaded"}
			}
		else ;//switching ammo
			{delay 4
				{ani_play "shell_eject" 1.0}
			}
			{delay 12
				{talk "reloaded"}
			}
		}
		{delay 1
			{talk "reload"}
		}
	}

	{on "reload_delay" overload}

	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/karl_gerat/MB507C/start"}
		{link_sound "engine_stop"		"vehicle/engine/karl_gerat/MB507C/stop"}
		{link_sound "engine_idle"		"vehicle/engine/karl_gerat/MB507C/idle"}
		{link_sound "engine_full"		"vehicle/engine/karl_gerat/MB507C/full"}
		{link_sound "exhaust"			"vehicle/engine/karl_gerat/MB507C/exhaust"}
		{link_sound "move"				"vehicle/tracks/karl_gerat/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}

	{on ik begin "basis"			;// gun bone rotates (vertical rotation)
		{if cannon_state "fire"
			{play_sound "rotate_gun" 1}
			{ani_play "aim_v" loop resume}
			{ani_play "aim_h" loop resume}
		}
	}

	{on ik end "basis"				;// gun stops rotation
		{stop_sound "rotate_gun"}
		{ani_stop "aim_v"}
		{ani_stop "aim_h"}
	}

	{on fire "gun"
		{volumes "shell1" disable bullet blast}		;// Disables shell volume after firing while reloading
		{delay 12									;// Ables shell volume after firing while reloading
			{volumes "shell2" enable bullet blast}
		}
		{delay 22									;// Delay set to match reload time of main weapon
			{volumes "shell1" enable bullet blast}	;// Aables shell volume after reloading
			{volumes "shell2" disable bullet blast}	;// Disables shell volume after reloading
		}
	}

	{on break_armor					;// volume breaks
		{if not tagged "exploded"
			{if volume "shell1"
				{call "stat_break"}
				{call "_explosion"}
			else volume "shell2"
				{call "stat_break"}
				{call "_explosion"}
			}
		}
	}

	{on "explosion_blastwave" overload
		{blastwave c4 15 r0 7 r1 14 offset 0 0 75}
		{blastwave c4 2 r0 10 r1 20 offset 0 0 75}
		{impulse up 0.1 0.1 dir 0.2 0.1}
		{spawn "tank_die_heavy" "basis"}
		{start_sound "detonation/explosion_vehicle/bkg/"}
		{if terrain_fx "snow"
			{spawn "tank_die_snow" "basis"}
		else terrain_fx "ice"
			{spawn "tank_die_snow" "basis"}
		else
			{spawn "tank_die_dust" "basis"}
		}
	}

	{on contact overload
		{if not impregnable
			{if not effector "bicycle"
				{if effector "vehicle"
					{if effector_velocity 2
						{if not "fx_delay"
							{set "fx_delay" 1}
							{delay 2 "fx_delay"
								{set "fx_delay" 0}
							}
							{spawn "metal_crush" "root"}
						}
					}
				}
			}
		}
	}
}

{"300mm_nebelwerfer42"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	("cannon_small")
}
{"200mm_leldgw"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	("cannon_small")
}

;/*=========== Germans End ===========*/

;/*=========== Finnish Begin ===========*/

{"20mm_l39"
	("magazine" cut(0.6) show(2.7) override(overload) impulse({impulse up 0.3 forward 1.9 0.2}))
}


{"20mm_itk35"
	("magazine" cut(0.4) show(1.8) override(overload) impulse({impulse up 0.3 0.2 forward 1.9 0.2}))

	{on "cut_parts" overload
		("cut_part" args "wheell" 1)
		("cut_part" args "wheelr" 1)
		{inherited}
	}

	("cannon_small")
}

{"20mm_itk40"
	{on "init_gun"
		{link_sound "bkg_auto" "weapon/shot/bkg/auto/"}
	}
	{on "cut_parts" overload
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		{inherited}
	}
	("cannon_small")
}

{"37mm_pstk36"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.20 0.35)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}


	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_small")
}

{"47mm_pstk39"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		{inherited}
	}

	("cannon_small")
}

{"40mm_itk38b"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.45) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_small")
}

{"45mm_pstk32"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"75mm_pstk9738"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 3.5)
	}

	("cannon_small")
}

{"75mm_k44"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.55 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 4)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"75mm_itk37"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 5.0)
	}

	("cannon_big")

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "wheell1" 1)
		("cut_part" args "wheelr1" 1)
		("cut_part" args "wheell2" 1)
		("cut_part" args "wheelr2" 1)
		{inherited}
	}
}

{"76mm_m1927_fin"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.5)
	}

	("cannon_small")
}

{"76mm_k02_30_40"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}

	("cannon_small")
}

{"84mm_k18"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.75 0.5)
	}	
	{on "cut_parts" overload
		("cut_part" args "wheelL" 1)
		("cut_part" args "wheelR" 1)
		{inherited}
	}
	("cannon_big")
}

{"105mm_k13"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}

	("cannon_big")
}

{"105mm_k34"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}

	("cannon_big")
}

{"107mm_k10"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}

	("cannon_big")
}

{"120mm_k78_31"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}

{"122mm_m1910_fin"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 14)
	}

	("cannon_big")
}

{"155mm_h17"
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		{inherited}
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 30)
	}

	("cannon_big")
}

{"170mm_minewerfer"
	{on "self_destruct" overload
		{spawn "car_die" "basis"}
	}
}

{"203mm_h17"
	{on "spawn_shell_delay" overload}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 4 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 88)
	}

	("cannon_big")
}

;/*=========== Finnish End ===========*/

;/*=========== USA Begin ===========*/


{"m1917_30cal"
	{on "add_weapon_sound"
		("M1919A4")
	}
	{on "init_gun"
		{add_view "shell_mgun" "shell" "FXshell"}
		{add_view "ejectsmoke_big" "ejectsmoke" "FXshell"}
	}
	{on fire "mgun"
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{play_sound "action_recoil"}
		{view start "flashbarrel"}
		{delay 0.2 "fire"
			{view pause "flashbarrel"}
		}
		{kill_delay "shell_off"}
		{view start "shell"}
		{view start "ejectsmoke"}
		{delay 0.12 "shell_off"
			{view pause "shell"}
			{view pause "ejectsmoke"}
		}
	}
}
{"m2_30cal_tripod"
	{on "add_weapon_sound"
		("M1919A4")
	}
}
{"m2_50cal_tripod"
	{on "add_weapon_sound"
		("M2HB")
	}
}

{"50cal_quad_m45"				;// base code for multi-barrel cannons and vehicles. To customize, add unique code to specific cannon name prop
	("handle_ik")
	{on "add_weapon_sound" overload
		("M2HB_M45_Mount")
	}

	("multi_barrel_loop" flash(flash_gun_big) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "reload"
		{ani_play "reload_mgun" 1.0}
	}
	{on "reload_delay" overload
		("reload_time" args 30)		;// weapon reload time
	}

	("cannon_small")
}

{"37mm_m3"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.25 0.2)
	}

	{on "reload_delay" overload
		("reload_time" args 3)
	}

	("cannon_small")
}

{"40mm_m1"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay_auto" overload
		("shell_eject_delay_auto" args 0.45) ;// delay cannot be longer than rate of fire else shell ejection is skipped and only played on last shell.
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part1" 1)
		("cut_part" args "part3" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part8" 1)
		{inherited}
	}

	("cannon_small")
}

{"50mm_rocket_projector"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "cut_parts" overload			;// Forces Mortars to cut all parts instead of using random chance.
		("cut_part" args "part1" 1)		;// Looks odd when legs cut but barrel floats in air.
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 1)
		{inherited}
	}
}

{"57mm_m1"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 4.5)
	}

	("cannon_small")
}

{"75mm_m1897"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.9 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.5)
	}

	("cannon_small")
}


{"75mm_m1a1"
	{on "construction_sandbag_cannon_shallow" overload
		("cannon_sandbag" args "sandbag_cannon_shallow" "sandbag")
	}
	
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_small")
}

{"75mm_m3a3"
	{on "construction_sandbag_cannon_shallow" overload
		("cannon_sandbag" args "sandbag_cannon_shallow" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_small")
}

{"76mm_m5_m1"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.40 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 5.25)
	}

	("cannon_small")
}

{"76mm_m5_m6"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.40 0.25)
	}

	{on "reload_delay" overload
		("reload_time" args 5.25)
	}

	("cannon_small")
}

{"90mm_m1a1"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}

	("cannon_big")
	
	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "standf" 1)
		;("cut_part" args "pivot_front" 1)
		{inherited}
	}
}

{"105mm_m2a1"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}

	("cannon_big")
}

{"105mm_m3"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}

	("cannon_big")
}

{"107mm_m2"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
}

{"114mm_m1"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 20)
	}

	("cannon_big")
}

{"155mm_gpf"
	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}

	("cannon_big")
}

{"155mm_m1"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}
	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}

	("cannon_big")
}

{"155mm_m1a1_longtom"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}

	{on "cut_parts" overload
		("cut_part" args "gun" 0.6)
		("cut_part" args "gun_rot" 0.6)
		("cut_part" args "turret_mesh" 0.6)
		{inherited}
	}

	("cannon_big")
}

{"155mm_schneider_us"
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 30)
	}

	{on "cut_parts" overload
		("cut_part" args "part1" 1)
		{inherited}
	}

	("cannon_big")
}

{"203mm_m1"
	{on "construction_sandbag_cannon_standard" overload
		("cannon_sandbag" args "sandbag_cannon_standard" "sandbag")
	}

	{on "no_spawn_shell_delay" overload
		("no_shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 70)
	}

	{on "cut_parts" overload
		("cut_part" args "gun" 0.6)
		("cut_part" args "gun_rot" 0.6)
		("cut_part" args "turret_mesh" 0.6)
		{inherited}
	}

	("cannon_big")
}

;/*=========== Specific Cannons End ===========*/
