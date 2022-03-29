
;/*=========== Explosive Grenade Begin ===========*/

{"grenade"
	{on spawn
		{call "add_grenade_sound"}
		{play_sound "equip"}
	}
	{on "onThrow"
		{call "grenade_fx"}
		{delay 0.15
			{play_sound "spoon"}
		}
		{volumes "body" disable contact}
	}
	{on "onThrowActivate"
		{play_sound "pin"}
		{volumes "body" enable contact}
	}
	{on contact
		{if stuff_activated
			{if effector "human"
				{call "fall_down"}
		 	else effector "cannon"
				{link_grenade_to_nearest_human teleport}
			}
		}
	}
	{on "activate"
		{call "hide_marker"}
	}
	{on "in_hole"
		{break_window_in_hole}
		{link_grenade_to_nearest_human}
	}
	{on ground_hit
		{view stop "trace"}
		{if not terrain_fx "water"
			{if terrain_fx "bridge"
				{start_sound "hit/grenade/Dirt/"}
			else terrain_fx "bridge_wood"
				{start_sound "hit/grenade/Wood/"}
			else terrain_fx "bridge_steel"
				{start_sound "hit/grenade/Metal/"}
			else terrain_fx "bridge_snow"
				{start_sound "hit/grenade/Grass/"}
			else terrain_fx "grass"
				{start_sound "hit/grenade/Grass/"}
			else terrain_fx "ground"
				{start_sound "hit/grenade/Dirt/"}
			else terrain_fx "ice"
				{start_sound "hit/grenade/Rock/"}
			else terrain_fx "mud"
				{start_sound "hit/grenade/Mud/"}
			else terrain_fx "road"
				{start_sound "hit/grenade/Rock/"}
			else terrain_fx "country_road"
				{start_sound "hit/grenade/Dirt/"}
			else terrain_fx "rock"
				{start_sound "hit/grenade/Rock/"}
			else terrain_fx "sand"
				{start_sound "hit/grenade/Grass/"}
			else terrain_fx "snow"
				{start_sound "hit/grenade/Grass/"}
			}
		}
	}
	{on "fall_down"
		{volumes disable contact}
		{fall_down}
	}

	{on "show_marker1"
		{view start "marker1"}
		{view start "marker3"}
	}

	{on "show_marker2"
		{view pause "marker1"}
		{view start "marker2"}
		{view pause "marker3"}
		{view start "marker4"}
	}

	{on "hide_marker"
		{view stop "marker1"}
		{view stop "marker2"}
		{view stop "marker3"}
		{view stop "marker4"}
	}

	{on bullet_hit
		{stuff_detonate}
	}
	{on blast_hit
		{if min_energy 0.8
			{stuff_detonate}
		}
	}
	{on "grenade_fx"
		{view start "trace"}
	}
}

{"grenade fg"
	{on "onThrow"
		{delay 1.5
			{call "show_marker1"}
		}
		{delay 3.5
			{call "show_marker2"}
		}
	}
}

{"grenade dynamite"
	{on "undermine"
		{delay 7
			{call "show_marker1"}
		}
		{delay 9
			{call "show_marker2"}
		}
	}
	{on "onThrow"
		{call "undermine"}
	}
}

{"grenade contact"
	{on ground_hit
		{if stuff_activated
			{if not name "water"
				{call "ground_detonate"}
			}
		}
	}
	{on "in_hole" overload}
	{on contact
		{if stuff_activated
			{call "contact_detonate"}
		}
	}
	{on "ground_detonate"
		{call "detonate"}
	}
	{on "contact_detonate"
		{call "detonate"}
	}
	{on "detonate"
		{stuff_detonate}
	}
	{on "fall_down" overload}
}

{"grenade fire"
	{on spawn
		{add_view "molotov_lit" "lit" "wick"}
		{view hide "lit"}
		{play_sound "equip"}
	}
	{on "grenade_fx"
		{view show "lit"}
		{view start "lit"}
		{play_sound "loop" 1}
	}
	{on "ground_detonate"
		{fire radius 2.5 time 7 heating 1.5}
		{fire radius 1.5 time 20 heating 0.5}
	}
	{on "contact_detonate" overload
		{volumes disable bullet contact blast}
		{fire radius 1.25 time 2 heating 75 effector follow}
		{fire radius 1 time 20 heating 0.5 effector follow}
		{delay 0.01
			{call "detonate"}
		}
	}
	{on "onThrow"
		{play_sound "throw"}
	}
}

{"grenade magnetic"
	{on contact 
		{if material "steel"
			{physics_work 0}
			{volumes disable contact}
			{call "position_checker"}
		}
	}
	{on "position_checker"
		{volumes "body" enable contact}
		{delay 0 {physics_work 1}}
		{impulse up -0.01 com}
		{delay 0.25 "position_checker"
			{call "position_checker"}
		}
	}
}

{"grenade timed"
	{on contact
		{if stuff_activated
			{if effector "vehicle"
				{volumes disable bullet contact blast} ;// keeps grenade from detonating multiple times (multiple blastwaves)
				{stuff_detonate}
			}
		}
	}
}

;/*=========== Explosive Grenade End ===========*/

;/*=========== Smoke Grenade Begin ===========*/

{"grenade smoke"
	{on spawn
		{call "add_smoke"}
	}
	{on "add_smoke"
		{add_view "spark_grenade"			"sparks" "fx_smoke"}
		{add_view "smoke_grenade_launcher_init"		"smoke0" "fx_smoke"}
		{add_view "smoke_grenade_launcher"		"smoke1" "fx_smoke"}
		{add_view "smoke_cover_norm"			"smoke2" "root"}
		{add_view "smoke_cover_big"			"smoke3" "root"}
		{add_view "smoke_grenade_launcher_init"		"smoke4" "fx_smoke"}
	}
	{on "onThrow" overload
		{delay 0.1
			{if stuff_activated
				{if not tagged "activated"
					{tags add "activated"}
					{call "activate"}
				}
			}
		}
	}
	{on ground_hit
		{if tagged "activated"
			{if name "water"
				{hide 1}
				{kill_delay "smoke"}
			}
		}
	}
	{on "activate"
		{volumes disable touch select}
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{play_sound "pop"}
		{play_sound "loop" 1}
		{view start "smoke0"}
		{view start "sparks"}
		{delay 1.5 "smoke"
			{view stop "smoke0"}
			{view start "smoke1"}
			{delay 1 "smoke"
				{view stop "sparks"}
				{view start "smoke1"}
				{view start "smoke2"}
				("spawn_volume" args cylinder 0 110 84)		;4
				("spawn_volume" args cylinder 0 0 84)		;5
				("spawn_volume" args cylinder 0 -110 84)	;6
				("spawn_volume" args cylinder 110 110 84)	;1
				("spawn_volume" args cylinder 110 0 84)		;2
				("spawn_volume" args cylinder 110 -110 84)	;3
				("spawn_volume" args cylinder -110 110 84)	;7
				("spawn_volume" args cylinder -110 0 84)	;8
				("spawn_volume" args cylinder -110 -110 84)	;9
			}
		}
		{delay 6 "smoke"
			{view start "smoke3"}
			("spawn_volume" args cylinder_sm 220 0 82)
			("spawn_volume" args cylinder_sm -220 0 82)
			("spawn_volume" args cylinder_sm 0 220 82)
			("spawn_volume" args cylinder_sm 0 -220 82)
		}
		{delay 90 "smoke"
			{view stop "smoke2"}
			{view stop "smoke3"}
		}
		{delay 100 "smoke"
			{stop_sound "loop"}
			{view stop "sparks"}
		}
		{delay 115 "smoke"
			{view start "smoke4"}
			{view stop "smoke1"}
		}
		{delay 150 "smoke"
			{call "delete_grenade"}
		}
	}
	{on "delete_grenade"
		{hide 1}
		{stop_sound "pop"}
		{stop_sound "loop"}
		{view stop "sparks"}
		{view stop "smoke0"}
		{view stop "smoke1"}
		{view stop "smoke2"}
		{view stop "smoke3"}
		{view stop "smoke4"}
	}
	{on blast_hit overload}			;// keeps smoke grenades from deleting by blast damage after being thrown
	{on bullet_hit overload}		;// keeps smoke grenades from deleting by bullet hit after being thrown
}

{"grenade smoke launcher"			;// Smoke grenades for vehicles
	{on "add_smoke"
		{add_view "spark_grenade"			"sparks" "fx_smoke"}
		{add_view "smoke_grenade_launcher_init"		"smoke0" "fx_smoke"}
		{add_view "smoke_grenade_launcher"		"smoke1" "fx_smoke"}
		{add_view "smoke_cover_norm"			"smoke2" "root"}
		{add_view "smoke_cover_big"			"smoke3" "root"}
	}
	{on "onThrow" overload
		{delay 0.1
			{if stuff_activated
				{if not tagged "activated"
					{tags add "activated"}
					{call "activate"}
				}
			}
		}
	}
	{on ground_hit
		{if tagged "activated"
			{if name "water"
				{hide 1}
				{kill_delay "smoke"}
			}
		}
	}
	{on "activate"
		{volumes disable touch select}
		(define "spawn_volume"
			{spawn "smoke_volume_%0" offset %1 %2 0
				{delay %3 {hide 1}}
			}
		)
		{play_sound "pop"}
		{play_sound "loop" 1}
		{view start "smoke0"}
		{view start "sparks"}
		{delay 1.5 "smoke"
			{view stop "smoke0"}
			{view start "smoke1"}
			{delay 1 "smoke"
				{view stop "sparks"}
				{view start "smoke1"}
				{view start "smoke2"}
				("spawn_volume" args cylinder 0 110 84)		;4
				("spawn_volume" args cylinder 0 0 84)		;5
				("spawn_volume" args cylinder 0 -110 84)	;6
				("spawn_volume" args cylinder 110 110 84)	;1
				("spawn_volume" args cylinder 110 0 84)		;2
				("spawn_volume" args cylinder 110 -110 84)	;3
				("spawn_volume" args cylinder -110 110 84)	;7
				("spawn_volume" args cylinder -110 0 84)	;8
				("spawn_volume" args cylinder -110 -110 84)	;9
			}
		}
		{delay 6 "smoke"
			{view start "smoke3"}
			("spawn_volume" args cylinder_sm 220 0 82)
			("spawn_volume" args cylinder_sm -220 0 82)
			("spawn_volume" args cylinder_sm 0 220 82)
			("spawn_volume" args cylinder_sm 0 -220 82)
		}
		{delay 90 "smoke"
			{view stop "smoke3"}
		}
		{delay 110 "smoke"
			{view stop "smoke2"}
		}
		{delay 110 "smoke"
			{stop_sound "loop"}
			{view stop "sparks"}
		}
		{delay 115 "smoke"
			{view start "smoke4"}
			{view stop "smoke1"}
		}
		{delay 140 "smoke"
			{call "delete_grenade"}
		}
	}
	{on "delete_grenade"
		{hide 1}
		{stop_sound "pop"}
		{stop_sound "loop"}
		{view stop "sparks"}
		{view stop "smoke0"}
		{view stop "smoke1"}
		{view stop "smoke2"}
		{view stop "smoke3"}
		{view stop "smoke4"}
	}
	{on blast_hit overload}			;// keeps smoke grenades from deleting by blast damage after being thrown
	{on bullet_hit overload}		;// keeps smoke grenades from deleting by bullet hit after being thrown
}

{"grenade smoke yellow"
	{on "add_smoke" overload
		{add_view "smoke_yellow_small"	"smoke1" "root"}
		{add_view "smoke_yellow_norm"	"smoke2" "root"}
		{add_view "smoke_yellow_big"	"smoke3" "root"}
	}
}

;/*=========== Smoke Grenade End ===========*/

;/*=========== Throw Sounds Begin ===========*/

{"f1"
	{on "add_grenade_sound" overload
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
		{link_sound "spoon" 	"weapon/foley/F1_spoon"}
	}
}
{"rgd33"
	{on "add_grenade_sound" overload
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
	}
}

{"m24"
	{on "add_grenade_sound" overload
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
	}
}
{"m24_smoke"
	{on "add_grenade_sound" overload
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
		{link_sound "loop" 	"detonation/grenade_smoke/generic/smoke_loop_01"}
		{link_sound "pop" 	"detonation/grenade_smoke/generic/pop/"}
	}
}
{"m24_smoke_ammo"
}

{"m24_smoke_weapons"
}

{"m24_geballteladung"
	{on "add_grenade_sound" overload
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
	}
}

{"molotov_cocktail"
	{on "add_grenade_sound" overload
		{link_sound "equip" 	"weapon/equip/grenade/molotov_equip"}
		{link_sound "throw" 	"weapon/shot/grenade/molotov_throw"}
		{link_sound "loop" 	"weapon/equip/grenade/molotov_loop"}
	}
}

{"rdg1_smoke"
	{on "add_grenade_sound" overload
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
		{link_sound "loop" 	"detonation/grenade_smoke/generic/smoke_loop_01"}
		{link_sound "pop" 	"detonation/grenade_smoke/generic/pop/"}
	}
}

{"nbk39"
	{on "add_grenade_sound"
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
		{link_sound "loop" 	"detonation/grenade_smoke/generic/smoke_loop_01"}
		{link_sound "pop" 	"detonation/grenade_smoke/generic/pop/"}
	}
}

{"no8_smoke"
	{on "add_grenade_sound"
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
		{link_sound "loop" 	"detonation/grenade_smoke/generic/smoke_loop_01"}
		{link_sound "pop" 	"detonation/grenade_smoke/generic/pop/"}
	}
}

{"pwm_l"
	{on "add_grenade_sound" overload
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
	}
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"rpg40"
	{on "add_grenade_sound" overload
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
	}
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload}	;disables detonation except when thrown. Prevents cumulative crash
}

{"rpg43"
	{on "add_grenade_sound" overload
		{link_sound "equip" 	"weapon/equip/grenade/grenade_deploy"}
	}
	{on bullet_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
	{on blast_hit overload} ;disables detonation except when thrown. Prevents cumulative crash
}

;=========== Throw Sounds End ===========*/