
;/*=========== German Vehicles Begin ===========*/

{"kfz13 tank"
	("kfz13_sound")
}
{"kfz14 tank"
	("kfz13_sound")
	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "commander_hatch_open" overload
		{ani_wind "binocular" end}
	}
	{on "commander_hatch_close" overload
		{ani_wind "binocular" begin}
	}
}
{"sdkfz221 tank"
	("sdkfz222_sound")
}
{"sdkfz222a tank"
	("sdkfz222_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on spawn
		{ani_wind "open" end}
	}

	{##on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{##on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"sdkfz223 tank"
	("sdkfz222_sound")
}
{"sdkfz231 tank"
	("sdkfz232_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"sdkfz232 tank"
	("sdkfz232_sound")
}
{"sdkfz234 tank"
	("sdkfz234_sound")

	{on pierce overload
		{if volume "turret"
			;do nothing    ;// disables kill_crew events when turret is pen. Calls for kill_crew are in gun_shield code for this vehicle.
		else
			{inherited}
		}
	}
}
{"sdkfz234_1 tank"
	("sdkfz234_sound")
	{on "add_weapon_sound" overload
		("MG42")
	}
	{on spawn
		{ani_wind "open" end}
	}
}
{"sdkfz234_2 tank"
	("sdkfz234_sound")
	{on "add_weapon_sound" overload
		("MG42")
	}
}
{"sdkfz234_3 tank"
	("sdkfz234_sound")
	{on "add_weapon_sound" overload
		("MG42")
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
}
{"sdkfz234_4 tank"
	("sdkfz234_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.15 0.05)
	}
	{on "reload_delay" overload
		("reload_time" args 5.25)		;// weapon reload time
	}
}
{"p204_f tank"
	("sdkfz234_sound") ;Placeholder
	{on "add_weapon_sound" overload
		("MAC31")
	}
}
{"p204_f_rail tank"
	("sdkfz234_sound") ;Placeholder
	{on "add_weapon_sound" overload
		("MAC31")
	}
}
{"panzer742r tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"sdkfz250a_1 tank"
	("hanomag_sound")
	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner4_hatch_open" overload
		{ani_play "mgun_aa_2" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun_aa_2" -1.0 resume}
	}
}
{"sdkfz250a_3 tank"
	("hanomag_sound")

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner4_hatch_open" overload
		{ani_play "mgun_aa_2" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun_aa_2" -1.0 resume}
	}
	{on "commander_hatch_open" overload
		{ani_wind "binocular" end}
	}
	{on "commander_hatch_close" overload
		{ani_wind "binocular" begin}
	}
}
{"sdkfz250a_9 tank"
	("hanomag_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on spawn
		{ani_wind "open" end}
	}

	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun

	{##on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{##on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"sdkfz250a_11 tank"
	("hanomag_sound")

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner4_hatch_open" overload
		{ani_play "mgun_aa_2" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun_aa_2" -1.0 resume}
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.15 0.1)
	}
	{on "reload_delay" overload
		("reload_time" args 2.0)
	}
}
{"sdkfz251c tank"
	("hanomag_sound")

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner4_hatch_open" overload
		{ani_play "mgun_aa_2" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun_aa_2" -1.0 resume}
	}
}
{"sdkfz251c_2 tank"
	("hanomag_sound")

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner4_hatch_open" overload
		{ani_play "mgun_aa_2" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun_aa_2" -1.0 resume}
	}
}
{"sdkfz251d_1 tank"
	("hanomag_sound")

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner4_hatch_open" overload
		{ani_play "mgun_aa_2" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun_aa_2" -1.0 resume}
	}
}
{"sdkfz251d_1_stuka tank"
	("hanomag_sound")

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner4_hatch_open" overload
		{ani_play "mgun_aa_2" +1.0 resume}
	}
	{on "gunner4_hatch_close" overload
		{ani_play "mgun_aa_2" -1.0 resume}
	}

	("rocket_weapon" args gun)		;// defines weapon place that is disabled while vehicle is on move

	{on fire "rocket"
		{volumes "rocket" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
	}
	{on "reload"
		{if name "rocket"
			{delay 300										;// Delay set to match reload time of main weapon
				{volumes "rocket" enable bullet blast}
			}
		}
	}

	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "rocket"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
		}
	}
	{on "explosion_extra"
		{blastwave c4 9 r0 4 r1 15 offset 0 0 25}
		{blastwave c4 1.3 r0 15 r1 25 offset 0 0 25}
		{spawn "train_die" "basis"}
	}
}
{"sdkfz251d_16 tank"
	("hanomag_sound")

	{on spawn
		{add_view "flamer_fire_tank" "gun" "foresight1"}
		{add_view "flamer_fire_tank" "gun1" "foresight2"}
	}

	{on "event_no_crew" overload}
	{on "event_with_crew" overload}

	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}

	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 60 1 40)
	("flame_weapon" args gun1 60 2 40)
}
{"sdkfz251d_17 tank"
	("hanomag_sound")

	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
}
{"sdkfz251d_21 tank"
	("hanomag_sound")
	{on "add_weapon_sound" overload
		("MG151_15_Drilling")
	}
	("multi_barrel_loop" flash(flash_gun_hmg_m2hb) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(gun) head(0.081))

	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
}
{"sdkfz251d_22 tank"
	("hanomag_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}
	{on "reload_delay" overload
		("reload_time" args 5.25)	;// weapon reload time
	}
}
{"sdkfz10_pak38 tank"
	("hanomag_sound")

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.20 0.2)
	}
	{on "reload_delay" overload
		("reload_time" args 3.75)	;// weapon reload time
	}
}
{"sdkfz4 tank"
	("hanomag_sound")
}
{"panzerwerfer42 tank"
	("hanomag_sound")

	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}

	("rocket_weapon" args gun)		;// defines weapon place that is disabled while vehicle is on move
}
{"sdkfz302"
	("sdkfz302_sound")
	{on "crew_stunned" overload}
	{on "crew_revive" overload}
	{on "driver_revive" overload}

	{on "explosion_blastwave" overload
		{start_sound "detonation/he_size5/bkg/"}
		{blastwave c4 45 r0 2.6 r1 5.2}
		{blastwave c4 13.05 r0 13.15 r1 18.85}
		{blastwave c4 1.538 r0 20.72 r1 30.08}

		{spawn "shockwave_sphere"}
		{spawn "ex_he_size6"}

		{spawn "crater_massive" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
	}
}
{"sdkfz303b"
	("sdkfz303_sound")
	{on "crew_stunned" overload}
	{on "crew_revive" overload}
	{on "driver_revive" overload}

	{on "explosion_blastwave" overload
		{start_sound "detonation/he_size5/bkg/"}
		{blastwave c4 65 r0 3 r1 6}
		{blastwave c4 14.325 r0 12.33 r1 21.23}
		{blastwave c4 1.476 r0 22.33 r1 31.83}

		{spawn "shockwave_sphere"}
		{spawn "ex_he_size6"}

		{spawn "crater_massive" "basis" x terrain_texmod}

		{if terrain_fx "snow"
			{spawn "tank_die_snow"}
		else terrain_fx "ice"
			{spawn "tank_die_snow"}
		else
			{spawn "tank_die_dust"}
		}
	}
}
{"sdkfz6_cargo"
	("hanomag_sound")
}
{"sdkfz6_2"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_gun" 		"vehicle/turret/gun/gun_vertical"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"				"vehicle/tracks/sdkfz251"}
	}

	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
}
{"sdkfz7"
	("hanomag_sound")
}
{"sdkfz7_2"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_gun" 		"vehicle/turret/gun/gun_vertical"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"				"vehicle/tracks/sdkfz251"}
	}
	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
}
{"sdkfz8_flak18 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"				"vehicle/tracks/sdkfz251"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.6 0.22)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
}
{"sdkfz4 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"				"vehicle/tracks/sdkfz251"}
	}
}
{"sdkfz7_1 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"				"vehicle/tracks/sdkfz251"}
	}
}
{"panzer1 tank"
	("pz1_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
	{on break						;// {on break} is for when components break
		{if not tagged "exploded"
			{if component "turret"
				{weapon_work "mgun" 0}
			else component "mantlet"
				{weapon_work "mgun" 0}
			}
		}
	}
	{on repair
		{if component "turret"
			{if work "mantlet"
				{weapon_work "mgun" 1}
			}
		else component "mantlet"
			{if work "turret"
				{weapon_work "mgun" 1}
			}
		}
	}
}
{"panzer1b tank"
	{on "add_weapon_sound" overload
		("MG13")
	}
}
{"panzer1f tank"
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzerjager1 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz1/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz1/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz1/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz1/full"}
		{link_sound "exhaust"			"vehicle/engine/pz1/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz1"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.15 0.05)
	}
	{on "reload_delay" overload
		("reload_time" args 3.5)		;// weapon reload time
	}
}
{"bison tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz1/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz1/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz1/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz1/full"}
		{link_sound "exhaust"			"vehicle/engine/pz1/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz1"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on pierce overload
		{if volume "turret"
			;do nothing    ;// disables kill_crew events when turret is pen. Calls for kill_crew are in gun_shield code for this vehicle.
		else
			{inherited}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.25)
	}
	{on "reload_delay" overload
		("reload_time" args 25)		;// weapon reload time
	}
}
{"panzer2c tank"
	("pz2_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer2f tank"
	("pz2_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on break
		{if not tagged "exploded"
			{if component "shieldw1"
				{components "shieldw2" destroy}
			}
			{if component "shieldw2"
				{components "shieldw1" destroy}
			}
		}
	}
}
{"panzer2l tank"
	("pz2_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"h39_turret tank"
	("pz2_sound")
	{on "add_weapon_sound" overload
		("MAC31")
	}
	{on "explosion_blastwave" overload
		{blastwave c4 3 r0 3 r1 8}
		{spawn "car_die" "basis"}
	}
	{on "cut_parts" overload					;// called on "_explosion" in vehicle prop
		(define "cut_part"
			{if rand %1
				{if tagged "ammo_broken"
					{tear "piece_medium_steel" bone %0
						{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
						{delay_effect 20 5 "stop"}			;// calls {on "stop"} in dummy.inc
					}
				else
					{tear "piece_medium_steel" bone %0
						{impulse up 4 1 dir 2.5 1 cx 2.5 1 cy 2.5 1 rnd_dir 5 no_position}
						{delay_effect 20 5 "stop"}			;// calls {on "stop"} in dummy.inc
					}
				}
			}
		)
		("cut_part" args "part1" 0.6)
		("cut_part" args "part2" 0.6)
	}
}
{"pz38h_735 tank"
	("pz2_sound")
	{on "add_weapon_sound" overload
		("MAC31")
	}
}
{"pz38h_w40 tank"
	("pz2_sound")
	{on "add_weapon_sound" overload
		("MAC31")
	}

	{on fire "rocket"
		{volumes "rocket" disable bullet blast contact}		;// Disables rocket volume after firing while reloading
	}
	{on "reload"
		{if name "rocket"
			{delay 300										;// Delay set to match reload time of main weapon
				{volumes "rocket" enable bullet blast}
			}
		}
	}
	
	{on break				;// volume breaks
		{if not tagged "exploded"
			{if component "rocket"
				{tags add "ammo_broken"}
				{call "stat_break"}
				{call "explosion"}
				{call "explosion_extra"}
			}
		}
	}
	{on "explosion_extra"
		{blastwave c4 9 r0 4 r1 15 offset 0 0 25}
		{blastwave c4 1.3 r0 15 r1 25 offset 0 0 25}
		{spawn "train_die" "basis"}
	}
}
{"marder2 tank"
	("pz2_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}
	{on "reload_delay" overload
		("reload_time" args 5.25)	;// weapon reload time
	}
}
{"grille_m tank"
	("pz38_sound")
	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
}
{"grille_k tank"
	("pz38_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.25)
	}
	{on "reload_delay" overload
		("reload_time" args 25)		;// weapon reload time
	}
}
{"marder3m tank"
	("pz38_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.30 0.25)
	}
	{on "reload_delay" overload
		("reload_time" args 5.25)	;// weapon reload time
	}
}
{"pz35t tank"
	("pz38_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	{##on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{##on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"pz38t_a tank"
	("pz38_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
}
{"pz38t_f tank"
	("pz38_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
	{on break
		{if not tagged "exploded"
			{if component "shieldw1"
				{components "shieldw2" destroy}
			}
		}
	}
}
{"pz38t_g tank"
	("pz38_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
}
{"hetzer tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/hetzer/start"}
		{link_sound "engine_stop"		"vehicle/engine/hetzer/stop"}
		{link_sound "engine_idle"		"vehicle/engine/hetzer/idle"}
		{link_sound "engine_full"		"vehicle/engine/hetzer/full"}
		{link_sound "exhaust"			"vehicle/engine/hetzer/exhaust"}
		{link_sound "move"				"vehicle/tracks/hetzer"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"panzer35s tank"
	("somua_s35_sound")
	{on "add_weapon_sound" overload
		("MAC31")
	}
}
{"panzer3e tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on spawn
		{add_view	"flash_gun_big" "flashbarrel00" "shooter00"}
		{add_view	"flash_gun_big" "flashbarrel01" "shooter01"}
	}
	{on fire "mgun2" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
	{on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"panzer3f tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"panzer3h tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer3j tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer3j1 tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer3j2 tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer3l tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer3m tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer3n tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer3_flamm tank"
	("pz3_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on spawn
		{add_view "flamer_fire_tank" "gun" "foresight1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 60 1 40)
}
{"stug3b tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"stug3e tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"sig33b tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"stug3f tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"stug3g tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "charger_hatch_open" overload
		{ani_wind "open1" end}
		{ani_play "mgun_aa" 1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "open1" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"stug3g_late tank"
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "gunner2_hatch_open" overload
		{ani_wind "open1" end}
		{ani_play "open" -1.0 resume}
	}
}
{"stuh42 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "charger_hatch_open" overload
		{ani_wind "open1" end}
		{ani_play "mgun_aa" 1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "open1" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"panzer4d tank"
	("pz4_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer4f1 tank"
	("pz4_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer4f2 tank"
	("pz4_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer4g tank"
	("pz4_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"panzer4h tank"
	("pz4_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"panzer4j tank"
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_heavy"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"wirbelwind tank"
	("pz4_sound")
	{on "init_gun"
		{link_sound "bkg_auto" "weapon/shot/bkg/auto/"}
	}
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
}
{"ostwind tank"
	("pz4_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
}
{"stug4g tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"sturmpanzer4 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "charger_hatch_open" overload
		{ani_wind "open1" end}
		{ani_play "mgun_aa" 1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "open1" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"jagdpanzer4_l48 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}

	{on "add_weapon_sound" overload
		("MG42")
	}
}
{"panzer4_70_v tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}

	{on "add_weapon_sound" overload
		("MG42")
	}
}
{"nashorn tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.1 0.4)
	}
	{on "reload_delay" overload
		("reload_time" args 7.5)	;// weapon reload time
	}
}
{"hummel tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)		;// weapon reload time
	}
}
{"wespe tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)		;// weapon reload time
	}
}
{"panzer5g tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"panzer5a tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"panzer5d tank"
	("pz5_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"jagdpanther tank"
	{on "add_weapon_sound" overload
		("MG42")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz5/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz5/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz5/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz5/full"}
		{link_sound "exhaust"			"vehicle/engine/pz5/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz5"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"panzerb2 tank"
	("char_b1_sound")
	{on "add_weapon_sound" overload
		("MAC31")
	}
}
{"pz756r tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on break
		{if not tagged "exploded"
			{if component "detail2"
				{components "detail2" destroy}
			}
		}
		("shed_shield_part" args "detail2")
	}
}
{"tiger1e tank"
	("pz6_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"tiger1h tank"
	("pz6_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"tiger1hunt tank"
	("pz6_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"ferdinand tank"
	("ferdinand_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}
}
{"sturmtiger"
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz6/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz6"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "bkg_cannon_huge"	"weapon/shot/bkg/cannon/huge/"}
		{link_sound "bkg_rocket"		"weapon/shot/bkg/rocket/"}
	}
	{on fire "gun"
		{play_sound "bkg_cannon_huge"}
		{play_sound "bkg_rocket"}
		{spawn "sturmtiger_fire" inv_normal}
		{volumes "rocket" disable bullet blast}		;// Disables rocket volume after firing while reloading
		{delay 90									;// Delay set to match reload time of main weapon
			{volumes "rocket" enable bullet blast}
		}
	}
	{on break_armor				;// volume breaks
		{if not tagged "exploded"
			{if volume "rocket"
				{call "stat_break"}
				{call "_explosion"}
				{##delay 0.01
					{call "spawn_shellhole"}
				}
			}
		}
	}
	{on "__explosion"
		{tags add "exploded"}
		{blastwave c4 15 r0 5 r1 12 offset 0 0 75}
		{blastwave c4 3 r0 12 r1 30 offset 0 0 75}
		{spawn "train_die" "basis"}
		{delay 0.1
			{call "_explosion"}
		}
	}
	{on "explosion_blastwave" overload
		{blastwave c4 9 r0 5 r1 10 offset 0 0 75}
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
}

{"tiger2h tank"
	("pz6b_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"tiger2p tank"
	("pz6b_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"jagdtiger tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz6b/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6b/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6b/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6b/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6b/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz6b"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "charger2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "charger2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}

;/*=========== German Vehicles End ===========*/

;/*=========== Soviet Vehicles Begin ===========*/

{"nkl26"
	("nkl_sound")
	{on "hatch_fire" overload} ;//disables typical hatch fire that tanks have on hull destroyed
;	{on "add_overlay_sound" overload} ;//disables standard track overlay sounds

}
{"gaz98"
	("nkl_sound")
	{on "hatch_fire" overload} ;//disables typical hatch fire that tanks have on hull destroyed

	{on "gunner_hatch_open"
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
		{tags add "gunner_hatch_open"}
		{tags remove "gunner_hatch_close"}
	}
	{on "gunner_hatch_close"
		{ani_play "mgun_aa" -1.0 resume}
		{tags remove "gunner_hatch_open"}
		{tags add "gunner_hatch_close"}
	}

	{on "cut_parts" overload
		("cut_part" args "part2" 1)
		("cut_part" args "part3" 0.8)
		("cut_part" args "part4" 0.8)
		("cut_part" args "part5" 0.8)
		("cut_part" args "part6" 0.8)
		{inherited}
	}
}

{"yag10_29k"
	("yag10_sound")

	{on fire "gun"
		{ani_play "recoil"}
	}

	("animation_sound" args "open_left")
	("animation_sound" args "open_right")

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.25 0.2)
	}
	{on "reload_delay" overload
		("reload_time" args 5)	;// weapon reload time
	}
	{on spawn
		{ani_wind "support_open" end}
	}
	{on move on
		{kill_delay "move_off"}
		{ani_play "support_open" -1.0 resume}
	}
	{on move off
		{delay 1 "move_off"
			{ani_play "support_open" 1.0 resume}
		}
	}
}

{"stalinetz60"
	("s60_sound")
}

{"ba64"
	("ba_sound")
}

{"fai_m"
	("ba_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}

{"ba20"
	("ba_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"ba20_command"
	("ba_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}

{"ba6"
	("ba_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}

{"ba10 tank"
	("ba_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}

{"m3a1e1_scout tank"
	("ba_sound")
}

{"m3a1e1_scout_mgun tank"
	("ba_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		{link_sound "action_recoil_HMG"		"weapon/action/recoil/closed_bolt_HMG/"}
	}
}

{"t20 tank"
	("t27_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"zis30 tank"
	("t27_sound")
}

{"bt2 tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"bt2_da2 tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun2" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
}
{"bt5 tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"bt7 tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"panzer742r tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"bt7a tank"
	("bt_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"kht26 tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
		{add_view "flamer_fire" "gun" "foresight1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 40 1 40)
}
{"kht130 tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
		{add_view "flamer_fire" "gun" "foresight1"}
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 45 1 40)
}
{"t26_31 tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
	}
	{on "update_turret"
		{if work "turret"
			{weapon_work "mgun2" 1}
		else
			{weapon_work "mgun2" 0}
		}
		{inherited}
	}
	{on "update_multi_turret"
		{if work "aux_turret2"
			{weapon_work "mgun3" 1}
		else
			{weapon_work "mgun3" 0}
		}
		{inherited}
	}
}
{"t26_33 tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		("rand_cut" args "turret_light")
		("rand_cut_else" args "cooler1" "cooler2")
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
}
{"t26_38 tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
		("rand_cut" args "turret_light")
		("rand_cut" args "antenna")
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
}
{"t26_39 tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		("rand_cut_else" args "cooler1" "cooler2")
		("rand_cut" args "turret_light")
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
}
{"su26 tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
}
{"t27 tank"
	("t27_sound")
}
{"t28 tank"
	("t28_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret2"
				{call "kill_gunner3"}
			else component "aux_turret1"
				{call "kill_charger2"}
			}
		}
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
	{on "update_multi_turret"
		{if work "aux_turret1"
			{weapon_work "mgun1" 1}
		else
			{weapon_work "mgun1" 0}
		}
		{if work "aux_turret2"
			{weapon_work "mgun2" 1}
		else
			{weapon_work "mgun2" 0}
		}
		{inherited}
	}
}
{"t35 tank"
	("t28_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on "lights_on"
		{ani_play "headlight"}
		{tags add "lights_on"}
	}
	{on "lights_off"
		{if tagged "lights_on"
			{ani_play "headlight" -1}
			{tags remove "lights_on"}
		}
	}
	
	{on break
		{if not tagged "exploded"
			{if component "aux_turret4"
				{call "kill_gunner6"}
			else component "aux_turret3"
				{if rand 0.5
					{call_synced "kill_gunner4"}
				else
					{call_synced "kill_charger4"}
				}
			else component "aux_turret2"
				{call "kill_gunner5"}
			else component "aux_turret1"
				{if rand 0.5
					{call_synced "kill_gunner3"}
				else
					{call_synced "kill_charger3"}
				}
			}
		}
	}
	{on "update_multi_turret"
		{if work "aux_turret2"
			{weapon_work "mgun1" 1}
		else
			{weapon_work "mgun1" 0}
		}
		{if work "aux_turret4"
			{weapon_work "mgun2" 1}
		else
			{weapon_work "mgun2" 0}
		}
		{inherited}
	}
}

{"smk tank"
	("t28_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on break
		{if not tagged "exploded"
			{if component "aux_turret1"
				{if rand 0.5
					{call_synced "kill_gunner4"}
				else
					{call_synced "kill_charger3"}
				}
			}
		}
	}
}

{"t37a tank"
	("t27_sound")
}
{"panzer731r tank"
	("t27_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t30 tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t40 tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("DT")
		("DShK38_int")
	}
}
{"t50 tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun2" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
}
{"t60 tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t60_bm8_24 tank"
	("t70_sound")

	("rocket_weapon" args gun)		;// defines weapon place that is disabled while vehicle is on move
}
{"t70 tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t70m tank"
	("t70_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"su76 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t70/start"}
		{link_sound "engine_stop"		"vehicle/engine/t70/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t70/idle"}
		{link_sound "engine_full"		"vehicle/engine/t70/full"}
		{link_sound "exhaust"			"vehicle/engine/t70/exhaust"}
		{link_sound "move"				"vehicle/tracks/t70"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 5)		;// weapon reload time
	}
}
{"zsu37 tank"
	("t70_sound")
}

{"t3457_41 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t3457_43 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t3476_40 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t3476_41 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on "cut_parts" overload
		("cut_part" args "part8" 1)
		("cut_part" args "part15" 1)
		{inherited}
	}
}
{"t3476_41e tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t3476_42 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t3476_43 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t3476_43_flame tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		{add_view "flamer_fire_tank" "flamer1" "foresight4"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 4 45)
}

{"t3485_44 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t3485_44_flame tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		{add_view "flamer_fire_tank" "flamer1" "foresight4"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 4 45)
}
{"t3485_44a tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"t3485_44a_flame tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		{add_view "flamer_fire_tank" "flamer1" "foresight4"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 4 45)
}
{"t3485_44b tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}

{"su85 tank"
	("su85_sound")
}
{"su85m tank"
	("su85_sound")
}
{"su100 tank"
	("su85_sound")
}
{"su122 tank"
	("su85_sound")
}
{"kv1_39 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"kv1_40 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"kv1_41 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"kv1_42 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"kv1s tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"kv2_40 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"kv85 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"kv8 tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		{add_view "flamer_fire_tank" "flamer1" "foresight7"}
	}
	{on operatable on
		{view start "fire"}
	}
	{on operatable off
		{view stop "fire"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 60 7 40)
}

{"su100y tank" ;// Temp until it gets it's own sound
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/kv/start"}
		{link_sound "engine_stop"		"vehicle/engine/kv/stop"}
		{link_sound "engine_idle"		"vehicle/engine/kv/idle"}
		{link_sound "engine_full"		"vehicle/engine/kv/full"}
		{link_sound "exhaust"			"vehicle/engine/kv/exhaust"}
		{link_sound "move"				"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
}
{"su152 tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/kv/start"}
		{link_sound "engine_stop"		"vehicle/engine/kv/stop"}
		{link_sound "engine_idle"		"vehicle/engine/kv/idle"}
		{link_sound "engine_full"		"vehicle/engine/kv/full"}
		{link_sound "exhaust"			"vehicle/engine/kv/exhaust"}
		{link_sound "move"				"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "cut_parts" overload
		("cut_part" args "engine_hatch" 1)
		{inherited}
	}
}
{"is1_43 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"is2_43 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"is2_44 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}
{"is2_45 tank"
	("is_sound")
	{on "add_weapon_sound" overload
		("DT")
		("DShK38")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"isu122s tank"
	{on "add_weapon_sound" overload
		("DShK38")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/is/start"}
		{link_sound "engine_stop"		"vehicle/engine/is/stop"}
		{link_sound "engine_idle"		"vehicle/engine/is/idle"}
		{link_sound "engine_full"		"vehicle/engine/is/full"}
		{link_sound "exhaust"			"vehicle/engine/is/exhaust"}
		{link_sound "move"				"vehicle/tracks/is/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open_right" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_right" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"isu152 tank"
	{on "add_weapon_sound" overload
		("DShK38")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/is/start"}
		{link_sound "engine_stop"		"vehicle/engine/is/stop"}
		{link_sound "engine_idle"		"vehicle/engine/is/idle"}
		{link_sound "engine_full"		"vehicle/engine/is/full"}
		{link_sound "exhaust"			"vehicle/engine/is/exhaust"}
		{link_sound "move"				"vehicle/tracks/is/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open_right" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_right" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}


;/*=========== Soviet Vehicles End ===========*/

;/*=========== Finnish Vehicles Begin ===========*/

{"ba10_fin tank"
	("ba_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}

{"l182 tank"
	("ba_sound")
	{on "add_weapon_sound" overload
		("LS26")
	}
}

{"ft17_fin tank"
	("pz1_sound")
}

{"ft17_mg_fin tank"
	("pz1_sound")
	{on "add_weapon_sound" overload
		("Maxim_Gun")
	}
}

{"vickers_6t_altb tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("Maxim_Gun")
		("KP31")
	}
	{on fire "mgun1"
		{play_sound "SMG_Mid"}
		{play_sound "SMG_Far"}
	}
}

{"t26e tank"
	("t26_sound")
	{on "add_weapon_sound" overload
		("DT")
		("KP31")
	}
	{on fire "mgun1"
		{play_sound "SMG_Mid"}
		{play_sound "SMG_Far"}
	}
}

{"bt42 tank"
	("bt_sound")
}

{"l62 tank"
	("bt_sound")
}

{"stug3g_fin tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "charger_hatch_open" overload
		{ani_wind "open1" end}
		{ani_play "mgun_aa" 1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "open1" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}


{"kv1_42_fin tank"
	("kv_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
}

;/*=========== Finnish Vehicles End ===========*/


;/*=========== USA Vehicles Begin ===========*/

{"m6_gmc"
	("wc51_sound")

	{on fire "gun"
		{ani_play "recoil"}
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.25 0.2)
	}
	{on "reload_delay" overload
		("reload_time" args 3)	;// weapon reload time
	}
}

{"m2_halftrack tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}
{"m2a1_halftrack tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}
{"m3_gmc tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.9 0.3)
	}

	{on "reload_delay" overload
		("reload_time" args 6.5)
	}
}
{"m3_halftrack tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M1919A4")
	}
}
{"m3a1_transport tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
}
{"m3a1_scout tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M1919A4")
		("M2HB")
	}
}
{"m3a1_commander tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M1919A4")
		("M2HB")
	}
	{on "commander_hatch_open" overload
		{ani_wind "binocular" end}
	}
	{on "commander_hatch_close" overload
		{ani_wind "binocular" begin}
	}
}
{"m3a1_halftrack tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}
{"m4_mortar_carrier tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M1919A4")
	}
}
{"m4a1_mortar_carrier tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}
{"m8_greyhound tank"
	("m8_greyhound_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
		("M2HB")
	}
}
{"m13_mgmc tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")

	{on "add_weapon_sound" overload
		("M2HB_M33_Mount")
	}

	("multi_barrel_loop" flash(flash_gun_big) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.115))

	{on "reload"
		{ani_play "reload_mgun" 1.0}
	}
	{on "reload_delay" overload
		("reload_time" args 15)	;// weapon reload time
	}
}
{"m15a1_cgmc tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")

	{on "add_weapon_sound" overload
		("M2HB_M33_Mount")
	}

	("multi_barrel_loop" flash(flash_gun_big) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.115))

	{##on "reload" ;// not specific to mgun reload. off until specific weapon reload
		{ani_play "reload_mgun" 1.0}
	}

	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
}
{"m16_mgmc tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")

	{on "add_weapon_sound" overload
		("M2HB_M45_Mount")
	}

	("multi_barrel_loop" flash(flash_gun_big) smoke(ejectsmoke_big) shell(shell_hmgun) weapon(mgun) head(0.070))

	{on "reload"
		{ani_play "reload_mgun" 1.0}
	}
	{on "reload_delay" overload
		("reload_time" args 30)	;// weapon reload time
	}
}
{"m20 tank"
	("m8_greyhound_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
}
{"m21_mortar_carrier tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")

	{on "add_weapon_sound" overload
		("M2HB")
	}
}
{"t19_hmc tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2.0 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 15)
	}
}
{"t30_hmc tank"
	("m3_halftrack_sound")
	("animation_sound" args "open_left")
	("animation_sound" args "open_right")
	{on "add_weapon_sound" overload
		("M2HB")
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 6)
	}
}
{"m5_hst tank"
	("m3_stuart_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m3_stuart_early tank"
	("m3_stuart_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on "add_weapon_sound" overload
		("M1919A4")
	}
	{on fire "mgun3" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m3_stuart_late tank"
	("m3_stuart_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on "add_weapon_sound" overload
		("M1919A4")
	}
	{on fire "mgun3" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m3a1_stuart tank"
	("m5a1_stuart_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m5a1_stuart tank"
	("m5a1_stuart_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m5a1_stuart_late tank"
	("m5a1_stuart_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m8_hmc tank"
	("m3_stuart_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
}
{"m18_hellcat tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
}
{"m18_hellcat_late tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
}
{"m24_chaffee tank"
	("m24_chaffee_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
		("M2HB")
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m3_lee tank"
	("m3_lee_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
	}
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{link_sound "move" "vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on fire "mgun1" overload
		{play_sound "MG_Mid"}
		{play_sound "MG_Far"}
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.2
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.2
				{view pause "flashbarrel01"}
			}
		}
	}
	{on break_armor					;// volume breaks
		{if volume "aux_turret2"
			{call "kill_commander"}
		}
	}
	{on break_armor_again			;// volume is broken again before related component is repaired
		{if volume "aux_turret2"
			{call "kill_commander"}
		}
	}
	{on break 
		{if component "aux_turret2"
			{weapon_work "mgun3" 0}
		}
	}
	{on repair
		{if component "aux_turret2"
			{weapon_work "mgun3" 1}
		}
	}
	(define "multi_turret_rotate"
		{on ik begin "%0" overload
			{kill_delay "rotate_turret%1"}
			{if not "rotate_turret%1"
				{play_sound "rotate_turret%1" 1}
				{set "rotate_turret%1" 1}
			}
		}
		{on ik end "%0" overload
			{delay 0.25 "rotate_turret%1"
				{stop_sound "rotate_turret%1"}
				{set "rotate_turret%1" 0}
			}
		}
	)
	("multi_turret_rotate" args aux_turret1 1)
	("multi_turret_rotate" args aux_turret2 2)
	("multi_gun_rotate" args gun1_rot)
}
{"m4_75_early tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4_75_early_armor tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4_75_late tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4_105 tank"
	("m4_105_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a1_75_early tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a1_75_late tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"t1e3_m4a1_75 tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a1_75_dd tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on "deep_water_check" overload
		{if chassis "water"
			{if not tagged "water_chassis"
				{ik_enable "turret" 0}
				{weapon_work "gun" 0}
				{weapon_work "mgun" 0}
				{weapon_work "mgun1" 0}
				{weapon_work "mgun2" 0}
				{ani_play "water"}
				{tags add "water_chassis"}
			}
		else tagged "water_chassis"
			{if work "turret" {ik_enable "turret" 1}}
			{if work "gun" {weapon_work "gun" 1}}
			{weapon_work "mgun" 1}
			{weapon_work "mgun1" 1}
			{weapon_work "mgun2" 1}
			{ani_play "water" -1}
			{tags remove "water_chassis"}
		}
	}
	{on "check_water_level" overload}
}
{"m4a1_75_mid tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open_right" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_right" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a1_75_mid_armor tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open_right" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_right" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a1_76w tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "charger_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a1_76w_mid tank"
	("m4_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "charger_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a2_75_early tank"
	("m4a2_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/steel/"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open_right" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_right" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a2_75_late tank"
	("m4a2_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/steel/"}
	}
	{on "commander_hatch_open" overload
		{ani_wind "open_right" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open_right" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a2_76w_early tank"
	("m4a2_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/steel/"}
	}
	{on "charger_hatch_open" overload
		{ani_wind "open_right" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "open_right" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a2_76w_late tank"
	("m4a2_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/steel/"}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a3_75_early tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a3_75_late tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a3_75w_early tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a3_75w tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m4a3_75w_e4_5 m4a3_75w tank"
	{on spawn
		{add_view "flamer_fire_tank" "flamer1" "foresight4"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 40 4 40)
}
{"m4a3_76w tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "charger_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "charger_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a3_76w_field tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}

{"m4a3_76w_hvss tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m4a3_105 tank"
	("m4a3_105_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a3_105_hvss tank"
	("m4a3_105_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"m4a3_calliope tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}

	("rocket_weapon" args rocket)		;// defines weapon place that is disabled while vehicle is on move
}
{"m4a3e2_75 tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m4a3e2_76 tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
		("M1919A4")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "gunner2_hatch_open" overload}
	{on "gunner2_hatch_close" overload}
}
{"m7_hmc tank"
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/M4_Sherman/start"}
		{link_sound "engine_stop"		"vehicle/engine/M4_Sherman/stop"}
		{link_sound "engine_idle"		"vehicle/engine/M4_Sherman/idle"}
		{link_sound "engine_full"		"vehicle/engine/M4_Sherman/full"}
		{link_sound "exhaust"			"vehicle/engine/M4_Sherman/exhaust"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 15)		;// weapon reload time
	}
}
{"m7b1_hmc tank"
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/M4A3_Sherman/start"}
		{link_sound "engine_stop"		"vehicle/engine/M4A3_Sherman/stop"}
		{link_sound "engine_idle"		"vehicle/engine/M4A3_Sherman/idle"}
		{link_sound "engine_full"		"vehicle/engine/M4A3_Sherman/full"}
		{link_sound "exhaust"			"vehicle/engine/M4A3_Sherman/exhaust"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 15)		;// weapon reload time
	}
}
{"m10_gmc tank"
	("m10_gmc_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
}
{"m10_gmc_late tank"
	("m10_gmc_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 6)		;// weapon reload time
	}
}
{"m12_gmc tank"
	("m4_sherman_sound")
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Rubber/"}
		{ani_wind "support_open" end}
	}
	{on engine on
		{kill_delay "move_off"}
		{ani_play "support_open" -1.0 resume}
	}
	{on engine off
		{delay 1 "move_off"
			{ani_play "support_open" 1.0 resume}
		}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)
	}
}
{"m36_gmc tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 8)		;// weapon reload time
	}
}
{"m36b1_gmc tank"
	("m4a3_sherman_sound")
	{on "add_weapon_sound" overload
		("M2HB")
	}
	{on spawn
		("rand_cut_else" args "bench1" "bench2")
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.75 1.25)
	}
	{on "reload_delay" overload
		("reload_time" args 8)		;// weapon reload time
	}
}
{"m26_pershing tank"
	("m26_pershing_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
		("M2HB")
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/M4_Sherman/Steel/"}
	}
	{on "gunner2_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner2_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"t26e4 m26_pershing tank"
	{on "commander_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"lvt4 tank"
	("m3_stuart_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
		("M2HB")
	}
	{on spawn
		{add_view	"flash_gun_hmg_m2hb"		"flashbarrel4"			"foresight15"}
	}
	{on fire "mgun1" overload
		{view start "flashbarrel4"}
		{play_sound "action_recoil_HMG"}
		{play_sound "HMG_Mid"}
		{play_sound "HMG_Far"}
		{delay 0.2
			{view pause "flashbarrel4"}
		}
	}
}


;/*=========== USA Vehicles End ===========*/


;/*=========== Generic Vehicles Begin ===========*/

{"universal_carrier_rus tank"
	("universal_carrier_sound")
}

{"mmg_carrier_rus tank"
	("universal_carrier_sound")
	{on "add_weapon_sound" overload
		("Maxim_Gun")
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
	}
	{on fire "mgun2"
		{ani_play "fire_mgun"}
		{play_sound "action_recoil"}
	}
	{on "reload"
		{if effector "stuff weapon"
		
		else
			{ani_play "reload_mgun"}
		}
	}
}

{"valentine2 tank"
	("valentine_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
}

{"valentine7 tank"
	("valentine_sound")
	{on "add_weapon_sound" overload
		("M1919A4")
	}
}

{"valentine9 tank"
	("valentine_sound")
}

{"churchill3 tank"
	("churchill_sound")
	{on "add_weapon_sound" overload
		("ZB37")
	}
}


;/*=========== Generic Vehicles End ===========*/


;/*=========== BK Vehicles Begin ===========*/

{"munitionspanzer38t tank"
	("pz38_sound")
}
{"tiger1mid tank"
	("pz6_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
}
{"tiger1mid#aa tank"
	("pz6_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
		{ani_play "mgun_aa" -1.0 resume}
	}
}
{"ot3476_42 tank"
	("t34_sound")
	{on "add_weapon_sound" overload
		("DT")
	}
	{on spawn
		{add_view "flamer_fire_tank" "flamer1" "foresight4"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args flamer1 80 4 45)
}
{"flammpanzer38t tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/hetzer/start"}
		{link_sound "engine_stop"		"vehicle/engine/hetzer/stop"}
		{link_sound "engine_idle"		"vehicle/engine/hetzer/idle"}
		{link_sound "engine_full"		"vehicle/engine/hetzer/full"}
		{link_sound "exhaust"			"vehicle/engine/hetzer/exhaust"}
		{link_sound "move"				"vehicle/tracks/hetzer"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on spawn
		{add_view "flamer_fire_tank" "gun" "foresight1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 60 1 40)
}
{"hummel_early tank"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
	}

	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 1.5 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 30)		;// weapon reload time
	}
}
{"elefant tank"
	("ferdinand_sound")
	{on "add_weapon_sound" overload
		("MG34")
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}
	{on "reload_delay" overload
		("reload_time" args 10)
	}
}
{"sdkfz251d_1 tank"
	("hanomag_sound")
	{on "add_weapon_sound" overload
		("MG42")
	}
	{on spawn
		{ani_wind "open" end}
	}
}

;/*=========== BK Vehicles End ===========*/
