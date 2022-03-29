
;/*=========== German Vehicles Begin ===========*/

{"sdkfz221 tank"
	("sdkfz222_sound")
}
{"sdkfz222 tank"
	("sdkfz222_sound")
}
{"sdkfz223 tank"
	("sdkfz222_sound")
}
{"sdkfz231 tank"
	("sdkfz232_sound")
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/zenite/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/zenite/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
}
{"sdkfz232 tank"
	("sdkfz232_sound")
}
{"sdkfz234 tank"
	("sdkfz234_sound")
}
{"sdkfz234_2 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG42/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG42/far/"}
	}
	("sdkfz234_sound")
}
{"p204_f tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/zenite/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/zenite/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/FRA/MAC1931/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/FRA/MAC1931/far/"}
	}
	("sdkfz234_sound") ;Placeholder
}
{"p204_f_rail tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/zenite/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/zenite/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/FRA/MAC1931/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/FRA/MAC1931/far/"}
	}
	("sdkfz234_sound") ;Placeholder
}
{"panzer742r tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("bt_sound")
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
{"sdkfz250a_11 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/zenite/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/zenite/"}
	}
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
		("reload_delay" args 2.0 0 0)
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
{"sdkfz251d tank"
	("hanomag_sound")
}
{"sdkfz10_pak38 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
	}
	("hanomag_sound")
}
{"sdkfz4 tank"
	("hanomag_sound")
}
{"sdkfz302"
	("sdkfz302_sound")
	{on "explosion_blastwave" overload
		{start_sound "detonation/explosion_large/close/"}
		{start_sound "detonation/explosion_large/mid/"}
		{start_sound "detonation/explosion_large/far/"}
		{start_sound "detonation/explosion_mechanical/shockwave/long/" use_position}
		{start_sound "detonation/explosion_mechanical/trickle/long/" use_position}
		{blastwave c4 15 r0 5 r1 8}
		{blastwave c4 1.5 r0 7 r1 12}


		{spawn "shockwave_sphere"}
		{spawn "ex_he_size4"}
		{spawn "crater_medium" terrain_texmod}

		{if terrain_fx "snow"
			{spawn "ex_he_size4_snow"}
		else terrain_fx "ice"
			{spawn "ex_he_size4_snow"}
		else
			{spawn "ex_he_size4"}
		}
	}
}
{"sdkfz303b"
	("sdkfz303_sound")
	{on "explosion_blastwave" overload
		{start_sound "detonation/explosion_massive/close/"}
		{start_sound "detonation/explosion_massive/mid/"}
		{start_sound "detonation/explosion_massive/far/"}
		{start_sound "detonation/explosion_mechanical/shockwave/long/" use_position}
		{start_sound "detonation/explosion_mechanical/trickle/long/" use_position}
		{blastwave c4 25 r0 5 r1 8}
		{blastwave c4 1.75 r0 7 r1 14}

		{spawn "shockwave_sphere"}
		{spawn "crater_big" terrain_texmod}

		{if terrain_fx "snow"
			{spawn "ex_he_size5_snow"}
		else terrain_fx "ice"
			{spawn "ex_he_size5_snow"}
		else
			{spawn "ex_he_size5"}
		}
	}
}
{"sdkfz8_flak18 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"			"vehicle/tracks/sdkfz251"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.3 0.22)
	}
	{on "reload_delay" overload
		("reload_delay" args 7.0 0.5 6.0)
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
		{link_sound "move"			"vehicle/tracks/sdkfz251"}
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
		{link_sound "move"			"vehicle/tracks/sdkfz251"}
	}
}

{"panzer1b tank"
	("pz1_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on fire "mgun" overload
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
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
{"panzer1f tank"
	("pz1_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on fire "mgun" overload
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
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
{"panzerjager1 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "engine_start"		"vehicle/engine/pz1/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz1/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz1/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz1/full"}
		{link_sound "exhaust"			"vehicle/engine/pz1/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz1"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.15 0.05)
	}
}
{"bison tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/very_large/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/very_large/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "engine_start"		"vehicle/engine/pz1/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz1/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz1/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz1/full"}
		{link_sound "exhaust"			"vehicle/engine/pz1/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz1"}
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
}

{"panzer2c tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/zenite/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/zenite/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz2_sound")
}
{"panzer2f tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/zenite/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/zenite/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz2_sound")
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/zenite/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/zenite/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz2_sound")
}

{"marder2 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
	}
	("pz2_sound")
}
{"grille_m tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/zenite/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/zenite/"}
	}
	("pz38_sound")
	{on "zenite_terrain_fx" overload} ; // overwrites and stops dust fx on ground from firing main gun
}
{"marder3m tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
	}
	("pz38_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.15 0.05)
	}
}
{"pz35t tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/37mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/37mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/Shared/ZB53/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/Shared/ZB53/far/"}
	}
	("pz38_sound")
	{##on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{##on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"pz38t_a tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/37mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/37mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/Shared/ZB53/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/Shared/ZB53/far/"}
	}
	("pz38_sound")
}
{"pz38t_f tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/37mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/37mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/Shared/ZB53/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/Shared/ZB53/far/"}
	}
	("pz38_sound")
	{on break
		{if not tagged "exploded"
			{if component "shieldw1"
				{components "shieldw2" destroy}
			}
		}
	}
}
{"pz38t_g tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/37mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/37mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/Shared/ZB53/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/Shared/ZB53/far/"}
	}
	("pz38_sound")
}
{"hetzer tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "engine_start"		"vehicle/engine/hetzer/start"}
		{link_sound "engine_stop"		"vehicle/engine/hetzer/stop"}
		{link_sound "engine_idle"		"vehicle/engine/hetzer/idle"}
		{link_sound "engine_full"		"vehicle/engine/hetzer/full"}
		{link_sound "exhaust"			"vehicle/engine/hetzer/exhaust"}
		{link_sound "move"			"vehicle/tracks/hetzer"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
	}
}

{"panzer3e tank"
	("pz3_sound")
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/37mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/37mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
		{add_view	"flash_gun_big" "flashbarrel00" "shooter00"}
		{add_view	"flash_gun_big" "flashbarrel01" "shooter01"}
	}
	{on fire "mgun2" overload
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
	{on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"panzer3f tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz3_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"panzer3j tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz3_sound")
}
{"panzer3j1 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz3_sound")
}
{"panzer3j2 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz3_sound")
}
{"panzer3l tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz3_sound")
}
{"panzer3m tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz3_sound")
}
{"panzer3n tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm_low-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz3_sound")
}
{"panzer3_flamm tank"
	("pz3_sound")
	{on spawn
		{add_view "flamer_fire_tank" "flame" "foresight1"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on fire "mgun1"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
	{on fire "mgun2"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 60 1 40)
}
{"stug3b tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm_low-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
}
{"stug3e tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm_low-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"				"vehicle/doors/pz4/open"}
		{link_sound "close"				"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
}
{"sig33b tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/very_large/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/very_large/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"				"vehicle/doors/pz4/open"}
		{link_sound "close"				"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
}
{"stug3f tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"				"vehicle/doors/pz4/open"}
		{link_sound "close"				"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
}
{"stug3g tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
	{on "gunner2_hatch_open" overload
		{ani_wind "open1" end}
		{ani_play "open" -1.0 resume}
	}
}
{"stuh42 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/large/105-122mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/large/105-122mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz3"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm_low-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz4_sound")
}
{"panzer4f1 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm_low-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz4_sound")
}
{"panzer4f2 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz4_sound")
}
{"panzer4g tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz4_sound")
}
{"panzer4h tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}

		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz4_sound")
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_heavy"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_heavy"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
}
{"stug4g tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
}
{"sturmpanzer4 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/very_large/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/very_large/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
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
{"jagdpanzer_iv tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
}
{"nashorn tank"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
}
{"hummel tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/very_large/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/very_large/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
}
{"wespe tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/large/105-122mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/large/105-122mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "open"			"vehicle/doors/pz4/open"}
		{link_sound "close"			"vehicle/doors/pz4/close"}
		{link_sound "open_driver"		"vehicle/doors/pz4/open_driver"}
		{link_sound "close_driver"		"vehicle/doors/pz4/close_driver"}
	}
}
{"welberwind tank"
	("pz4_sound")
}
{"panzer5g tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz5_sound")
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz5_sound")
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
	{on "commander_hatch_open" overload
		{ani_play "open" 1.0 resume}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz5_sound")
}
{"jagdpanther tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz5/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz5/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz5/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz5/full"}
		{link_sound "exhaust"			"vehicle/engine/pz5/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz5"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
	}
}
{"pz756r tank"
	("kv_sound")
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm/"}
		{link_sound 	"mgun_close"		"weapon/shot/small_arms/GER/MG34/close/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz6_sound")
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz6_sound")
	{on "commander_hatch_open" overload
		{ani_wind "open" end}
	}
	{on "commander_hatch_close" overload
		{ani_play "open" -1.0 resume}
	}
}
{"tiger1hunt tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz6_sound")
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("ferdinand_sound")
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 2 0.3)
	}
	{on "reload_delay" overload
		("reload_delay" args 3.5 0 0)
	}
}
{"elefant tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("ferdinand_sound")
}
{"sturmtiger"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/very_large/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/very_large/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz6/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz6"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
		{link_sound "bkg_cannon_huge"   	"weapon/shot/bkg/cannon/huge/"}
		{link_sound "bkg_rocket"        	"weapon/shot/bkg/rocket/"}
	}
	{on fire "gun"
		{play_sound "bkg_cannon_huge"}
		{play_sound "bkg_rocket"}
		{spawn "sturmtiger_fire" inv_normal}
	}
	{on fire "mgun1"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
	{on "__explosion"
		{if explosive_amount 30
			{blastwave c4 30 r0 8 r1 16}
			{blastwave c4 3 r0 20 r1 30}
			{spawn "train_die" "basis"}
			{delay 0.5
				{call "_explosion"}
			}
		}
	}

	{on break_armor				;// volume breaks
		;//{if not "broken"
			{if volume "rocket"
				;{if rand 0.40
					{call "stat_break"}
					{call "__explosion"}
					{delay 0.01
						{call "spawn_shellhole"}
					}
				;}
			}
		;//}
	}
}

{"tiger2h tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz6b_sound")
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	("pz6b_sound")
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/large/105-122mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/large/105-122mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz6b/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6b/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6b/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6b/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6b/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz6b"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
	}
}

;/*=========== German Vehicles End ===========*/

;/*=========== Soviet Vehicles Begin ===========*/

{"nkl26"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "engine_start"		"vehicle/engine/nkl/start"}
		{link_sound "engine_stop"		"vehicle/engine/nkl/stop"}
		{link_sound "engine_idle"		"vehicle/engine/nkl/idle"}
		{link_sound "engine_full"		"vehicle/engine/nkl/full"}
		{link_sound "engine_accelerate"	"vehicle/engine/nkl/accelerate"}
		{link_sound "engine_decelerate"	"vehicle/engine/nkl/decelerate"}
		{link_sound "move"				"vehicle/wheels/car/"}
		{link_sound "brake"				"vehicle/wheels/snow_skis/brake/"}

		{link_sound "wheel_ground"		"vehicle/wheels/snow_skis/overlay/ski_overlay_rock"}
		{link_sound "wheel_sand"		"vehicle/wheels/snow_skis/overlay/ski_overlay_snow"}
		{link_sound "wheel_grass"		"vehicle/wheels/snow_skis/overlay/ski_overlay_rock"}
		{link_sound "wheel_water"		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_puddle"		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_mud"			"vehicle/wheels/snow_skis/overlay/ski_overlay_snow"}
		{link_sound "wheel_snow"		"vehicle/wheels/snow_skis/overlay/ski_overlay_snow"}
		{link_sound "wheel_road"		"vehicle/wheels/snow_skis/overlay/ski_overlay_rock"}
		{link_sound "wheel_rock"		"vehicle/wheels/snow_skis/overlay/ski_overlay_rock"}
		{link_sound "wheel_wood"		"vehicle/wheels/snow_skis/overlay/ski_overlay_rock"}
	}
	{on "hatch_fire" overload} ;//disables typical hatch fire that tanks have on hull destroyed
;	{on "add_overlay_sound" overload} ;//disables standard track overlay sounds
}

{"stalinetz60"
	("s60_sound")
}

{"ba64"
	("ba_sound")
}

{"ba20"
	{on spawn
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	{on fire "mgun"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
	("ba_sound")
}

{"ba6"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("ba_sound")
}
{"ba10 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("ba_sound")
}
{"ba11 tank"
	("ba_sound")
}

{"m3a1e1_scout tank"
	("ba_sound")
}

{"m3a1e1_scout_mgun tank"
	{on spawn
		{link_sound 	"hmg_mid"	"weapon/shot/small_arms/USA/M2HB/mid/"}
		{link_sound 	"hmg_far"	"weapon/shot/small_arms/USA/M2HB/far/"}
		{link_sound 	"mid"		"weapon/shot/small_arms/USA/M1919A4/mid/"}
		{link_sound 	"far"		"weapon/shot/small_arms/USA/M1919A4/far/"}
	}
	{on fire "mgun"
		{play_sound	"hmg_mid"}
		{play_sound	"hmg_far"}
	}
	{on fire "mgun2"
		{play_sound	"mid"}
		{play_sound	"far"}
	}
	("ba_sound")
}

{"t20 tank"
	("t27_sound")
}
{"zis30 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t27_sound")
}

{"bt2 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("bt_sound")
}
{"bt2_da2 tank"
	("bt_sound")
	{on spawn
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
	}
	{on fire "mgun"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
	{on fire "mgun2" overload
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("bt_sound")
}
{"bt7 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("bt_sound")
}
{"bt7a tank"
	("bt_sound")
}
{"panzer742r tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("bt_sound")
}
{"bt7a tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm_low-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("bt_sound")
}
{"kht26 tank"
	("t26_sound")
	{on spawn
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
		("rand_cut_else" args "cooler1" "cooler2")
		{add_view "flamer_fire" "flame" "foresight1"}
	}
	{on fire "mgun2"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	("flame_weapon" args gun 40 1 40)
}
{"t26_31 tank"
	("t26_sound")
	{on spawn
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
		("rand_cut_else" args "cooler1" "cooler2")
	}
	{on fire "mgun2"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
	{on fire "mgun3"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
}
{"t26_33 tank"
	("t26_sound")
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
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

{"t27 tank"
	{on spawn
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	{on fire "mgun"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
	("t27_sound")
}
{"t28 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm_low-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t28_sound")
	{on break
		{if not tagged "exploded"
			{if component "aux_turret2"
				{call "kill_gunner3"}
			else component "aux_turret1"
				{call "kill_charger2"}
			}
		}
	}
}
{"t37a tank"
	{on spawn
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	{on fire "mgun"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
	("t27_sound")
}
{"panzer731r tank"
	("t27_sound")
	{on spawn
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	{on fire "mgun"
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
}
{"t30 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/zenite/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/zenite/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t70_sound")
}
{"t40 tank"
	{on spawn 
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
		{link_sound 	"hmg_mid"		"weapon/shot/small_arms/RUS/DShK/mid/"}
		{link_sound 	"hmg_far"		"weapon/shot/small_arms/RUS/DShK/far/"}
	}
	("t70_sound")
}
{"t60 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/zenite/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/zenite/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t70_sound")
}
{"t70 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t70_sound")
}
{"t70m tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t70_sound")
}
{"su76 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "engine_start"		"vehicle/engine/t70/start"}
		{link_sound "engine_stop"		"vehicle/engine/t70/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t70/idle"}
		{link_sound "engine_full"		"vehicle/engine/t70/full"}
		{link_sound "exhaust"			"vehicle/engine/t70/exhaust"}
		{link_sound "move"			"vehicle/tracks/t70"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
	}
	{on "spawn_shell_delay" overload
		("shell_eject_delay" args 0.4 0.3)
	}
}
{"zsu37 tank"
	("t70_sound")
}

{"t3457_41 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t34_sound")
}
{"t3457_43 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t34_sound")
}
{"t3476_40 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t34_sound")
}
{"t3476_41 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t34_sound")
}
{"t3476_42 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t34_sound")
}
{"t3476_43 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("t34_sound")
}
{"t3476_43_flame tank"
	("t34_sound")
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
		{add_view "flamer_fire_tank" "flame" "foresight4"}
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
	("flame_weapon" args flamer1 80 4 45)
}

{"t3485_44 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"			"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/electric/electric_light"}
	}
}
{"su85 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"				"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
	}
}
{"su100 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm_high-velocity/"}
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"				"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
	}
}
{"su122 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/large/105-122mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/large/105-122mm/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"			"vehicle/tracks/t34"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
	}
}

{"kv1_40 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("kv_sound")
}
{"kv1_41 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("kv_sound")
}
{"kv1s tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/75-76mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/75-76mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("kv_sound")
}
{"kv2_40 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/very_large/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/very_large/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("kv_sound")
}
{"kv85 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("kv_sound")
}
{"su100y tank" ;// Temp until it gets it's own sound
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/large/105-122mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/large/105-122mm_high-velocity/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/kv/start"}
		{link_sound "engine_stop"		"vehicle/engine/kv/stop"}
		{link_sound "engine_idle"		"vehicle/engine/kv/idle"}
		{link_sound "engine_full"		"vehicle/engine/kv/full"}
		{link_sound "exhaust"			"vehicle/engine/kv/exhaust"}
		{link_sound "move"			"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
	}
}
{"su152 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/very_large/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/very_large/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/kv/start"}
		{link_sound "engine_stop"		"vehicle/engine/kv/stop"}
		{link_sound "engine_idle"		"vehicle/engine/kv/idle"}
		{link_sound "engine_full"		"vehicle/engine/kv/full"}
		{link_sound "exhaust"			"vehicle/engine/kv/exhaust"}
		{link_sound "move"				"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
	}
}
{"is1_43 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/85-100mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/85-100mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("is_sound")
}
{"is2_43 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/large/105-122mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/large/105-122mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("is_sound")
}
{"is2_44 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/large/105-122mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/large/105-122mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
	("is_sound")
}
{"isu122s tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/large/105-122mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/large/105-122mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DShK/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DShK/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/is/start"}
		{link_sound "engine_stop"		"vehicle/engine/is/stop"}
		{link_sound "engine_idle"		"vehicle/engine/is/idle"}
		{link_sound "engine_full"		"vehicle/engine/is/full"}
		{link_sound "exhaust"			"vehicle/engine/is/exhaust"}
		{link_sound "move"			"vehicle/tracks/is/"}
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
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/very_large/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/very_large/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/RUS/DShK/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/RUS/DShK/far/"}
	}
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/is/start"}
		{link_sound "engine_stop"		"vehicle/engine/is/stop"}
		{link_sound "engine_idle"		"vehicle/engine/is/idle"}
		{link_sound "engine_full"		"vehicle/engine/is/full"}
		{link_sound "exhaust"			"vehicle/engine/is/exhaust"}
		{link_sound "move"			"vehicle/tracks/is/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/gun/gun_horizontal"}
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

;/*=========== Generic Vehicles Begin ===========*/

{"universal_carrier_rus tank"
	("universal_carrier_sound")
}

{"mmg_carrier_rus tank"
	{on spawn
		{link_sound 	"mgun_mid"	"weapon/shot/small_arms/RUS/PM1910/mid/"}
		{link_sound 	"mgun_far"	"weapon/shot/small_arms/RUS/PM1910/far/"}
	}
	("universal_carrier_sound")
	{on fire "mgun2"
		{ani_play "fire_mgun"}
		{play_sound	"mgun_mid"}
		{play_sound	"mgun_far"}
	}
	{on "reload"
		{if effector "stuff weapon"
		
		else
			{ani_play "reload_mgun"}
		}
	}
}
{"valentine2 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/Shared/ZB53/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/Shared/ZB53/far/"}
	}
	("valentine_sound")
}
{"valentine7 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/small/40-47mm/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/small/40-47mm/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/USA/M1919A4/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/USA/M1919A4/far/"}
	}
	("valentine_sound")
}
{"valentine9 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
	}
	("valentine_sound")
}
{"churchill3 tank"
	{on spawn
		{link_sound 	"cannon_mid"		"weapon/shot/gun/Shared/mid/medium/50-57mm_high-velocity/"}
		{link_sound 	"cannon_far"		"weapon/shot/gun/Shared/far/medium/50-57mm_high-velocity/"}
		{link_sound 	"mgun_mid"		"weapon/shot/small_arms/Shared/ZB53/mid/"}
		{link_sound 	"mgun_far"		"weapon/shot/small_arms/Shared/ZB53/far/"}
	}
	("churchill_sound")
}

;/*=========== Generic Vehicles End ===========*/
