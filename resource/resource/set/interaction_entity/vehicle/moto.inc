{"moto"

	{on "burst_mode"
		{if tagged "full_auto_mode"
			{tags remove "full_auto_mode"}
			{tags add "coax_burst_mode"}
			{damage_report "mgun" "Unit changed to burst mode"}
		else
			{tags add "full_auto_mode"}
			{tags remove "coax_burst_mode"}
			{damage_report "mgun" "Unit changed to full auto mode"}
		}
	}
	
	{inflammation_time 20}
	{on spawn
		{link_sound "flame" "fire/metal"}

;//		{if not rain
			{add_view	"dustrun_small"			"on_ground"			"FXtrace2"}
			{add_view	"dustrun_small"			"on_ground"			"FXtrace3"}
			{add_view	"dustrun_small"			"on_grass"			"FXtrace2"}
			{add_view	"dustrun_small"			"on_grass"			"FXtrace3"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtrace2"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtrace3"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtrace2"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtrace3"}
			{add_view	"dustrun_snow_small"	"on_snow"			"FXtrace2"}
			{add_view	"dustrun_snow_small"	"on_snow"			"FXtrace3"}
;//		}
		{add_view	"drops_water"			"on_water"			"FXtracel1"}
		{add_view	"drops_water_moto"		"on_puddle"			"FXtracel1"}

		{add_view	"smoke_broken_engine"	"smoke1"			"basis"}
		{add_view	"exhaust_dark_small"	"exhaust"			"FXsmoke1"}
	}

	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/r12/start"}
		{link_sound "engine_stop"		"vehicle/engine/r12/stop"}
		{link_sound "engine_idle"		"vehicle/engine/r12/idle"}
		{link_sound "engine_full"		"vehicle/engine/r12/full"}
		{link_sound "exhaust"			"vehicle/engine/r12/exhaust"}
		{link_sound "move"				"vehicle/wheels/bike"}
		{link_sound "brake"				"vehicle/wheels/brake"}
		{link_sound "rotate_turret"		""}
		{link_sound "rotate_gun"		""}
	}

	{on pierce sync
		{vehicle_health_damage_pierce}
	}

	(define "heavy_contact_fx"
		{if min_speed 5
			{if not "fx_delay"
				{set "fx_delay" 1}
				{delay 2 "fx_delay"
					{set "fx_delay" 0}
				}
				{spawn "%0" "root"}
			}
		}
	)
	(define "heavy_contact"
		{if min_speed 60
			{component break}
			{impulse up 0.3 0.05 forward 0.3 0.05}
		else min_speed 20
			{impulse up 0.2 0.05 forward 0.2 0.05}
		else min_speed 5
			{impulse up 0.1 0.05 forward 0.1 0.05}
		}
	)

	{on contact
		{if not impregnable
			{if effector "fence wood"
				("heavy_contact_fx" args wood_hit_piece)
			}
			{if effector_velocity 5
				{if effector "vehicle"
					{if not effector "bicycle"
						{if not effector "cannon_small"
							{call_synced "moto_crush_sync"}
						}
					}
				}
			else effector "no_crush"
				;do nothing
			else effector "dummy"
				;do nothing
			else effector "human"
				;do nothing
			else effector "concrete"
				("heavy_contact_fx" args metal_crush)
				("heavy_contact")
			else effector "steel"
				{if not effector "mine"
					{if not effector "stuff"
						("heavy_contact_fx" args metal_crush)
						("heavy_contact")
					}
				}
			else effector "sand"
				("heavy_contact_fx" args metal_crush)
				("heavy_contact")
			else effector "straw"
				("heavy_contact_fx" args metal_crush)
				("heavy_contact")
			else effector "tree"
				("heavy_contact_fx" args metal_crush)
				("heavy_contact")
			else not effector "fence wood"
				{if effector "wood"
					("heavy_contact_fx" args wood_hit_piece)
					("heavy_contact")
				}
			}
		}
	}
	
	{on "moto_crush_sync"
		{component break}
		{if volume "body"
			{set "crush" 1}
			{call "explosion"}
		}
	}

	{on break
		{if not tagged "exploded"
			{if component "body"
				{start_sound "crush/medium/metal"}
				{spawn "car_die_particle"}
				{crew_enable group "crew" 0}
				{reset_manual_control}
				{able select 0}			;// disables vehicle from being crewed until body is repaired
				{unlink_trailer}
			else component "engine"
				{start_sound "crush/medium/metal"}
				{tags add "engine_brake"}
				{spawn "car_die_particle" "engine"}
				{view start "smoke1"}
				{delay 40 {view pause "smoke1"}}
			}
		}
	}

	{on repair
		{if component "body"
			{crew_enable group "crew" 1}
			{able "select" 1}
			{tags remove "body_break"}
		else component "engine"
			{view pause "smoke1"}
		}
	}

	{on blast_hit		;// blastwave hits any part of entity
		{if min_energy 9
			{impulse up 2 0.125 dir 2.5 0.25}
		else min_energy 5
			{impulse up 1 0.125 dir 1.5 0.25}
		else min_energy 2
			{impulse up 0.5 0.125 dir 1 0.25}
		}
	}

	{on "_burn" overload
		{if not tagged "burned"
			{if not able "exploded"
				{talk "burning"}
				{add_view "smoke_dead_norm" "burn_fire" "basis"}
				{view start "burn_fire"}
				{burn time 7}
				{tags add "burned"}
				{play_sound "flame" 1}
				{set "burn_fire" 1}
				{call "stat_break"}
				{tags add "no_scavenge"}
				{explosive 1}
				{delay 1 0.5
					{call "check_burn_emit"}
				}
				{delay 5 1
					{explosive 0}
					{view stop "burn_fire"}
					{stop_sound "flame"}
					{call "explosion"}
				}
			}
		}
	}

	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}

	{on "check_burn_emit"
		{call "burn_emit"}
	}

	{on "_explosion"
		{area disable}
		{if not "crush"
			{spawn "car_die" "basis"}
			;{spawn "tank_die_particle" "basis"}
			{impulse up 4 2 dir 2 1}
		}
	}

	{on "spawn_shellhole"
		{spawn "shellhole_dead_moto2" "basis"}
	}

	{on "slice_load"
		{if name "wheel"
			{with_effector
				{add_view "smoke_dead_wheel" "smoke" "basis"}
			}
		}
	}

	{on "cut_parts"
		{add_view "fire_dead_vehicle_low" "deathfx" "basis"}
		{add_view "smoke_dead_vehicle" "deathfx_smoke" "basis"}
		{view start "deathfx"}
		{play_sound "flame" 1}
		{delay 300 50
			{view stop "deathfx"}
			{stop_sound "flame"}
			{view start "deathfx_smoke"}
			{delay 300 50
				{view stop "deathfx_smoke"}
			}
		}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				{burn first_volume fx "smoke_dead_wheel" time 20 5}
				{delay_effect 20 5 "stop"}
			}
		)
		(define "tear_wheel"
			{if rand 0.2
				{components "%0" destroy}
				{tear "piece_medium_steel" bone "%0" id "wheel"
					{volumes disable bullet contact blast}	;// prevents destroying at spawn moment
					{impulse up 6 4 dir 7 3}
					{add_view "smoke_dead_wheel" "smoke" "basis"}
					{view start "smoke"}
					{delay_effect 10 5 "pause"}
				}
			}
		)

		;{delay 14 {view stop "deathfx"}}

		("tear_wheel" args wheelleft1)
		("tear_wheel" args wheelleft2)
		("tear_wheel" args wheelright2)

		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
	}

	{on "gunner_hatch_open" overload
		{ani_play "mgun_aa" +1.0 resume}
	}
	{on "gunner_hatch_close"
		{ani_play "mgun_aa" -1.0 resume}
	}
	(define "places"
		{if has_place "%0"
			{if crew_in_place "%0"
				{call "%0_hatch_open"}
			else
				{call "%0_hatch_close"}
			}
		}
	)
	(define "update_hatch"
		{if operatable
			("places" args gunner)
		}
	)
	{on "update_hatch_on_spawn"
		("update_hatch")
	}
	(define "update_hatch_event"
		{on %event
			("update_hatch")
		}
	)
	("update_hatch_event" event(operatable on))
	("update_hatch_event" event(operatable off))
	("update_hatch_event" event(crew in))
	("update_hatch_event" event(crew out))
}

{"m72 moto"
	{on "link_weapon" overload
		{if effector "stuff weapon"
			{with_effector
				{call "link_open"}
			}
		}
	}
}

{"bicycle"
	{on spawn
		{set "engine_on" 0}
		{call "update_position_on_spawn"}
		{add_view 	"headlight_bike"	"lights"		"bike_light"}
		{add_view 	"headlight_bike"	"lights1"		"bike_light"}

		{add_view 	"light_vehicle_dim"	"lights"		"bike_light"}
		{add_view 	"light_vehicle_dim"	"lights1"		"bike_light"}
		
		{add_view	"drops_water"			"on_water"			"FXtraceR1"}
		{add_view	"drops_water"			"on_water"			"FXtraceL1"}
		{add_view	"drops_water_moto"		"on_puddle"			"FXtraceR1"}
		{add_view	"drops_water_moto"		"on_puddle"			"FXtraceL1"}

		;{link_sound "truck_open"		"vehicle/doors/truck/open"}

		{view hide "lights"}
		{view hide "lights1"}
	}

	{on "add_movement_sound" overload
		{link_sound "engine_start"		""}
		{link_sound "engine_stop"		""}
		{link_sound "engine_idle"		""}
		{link_sound "engine_full"		""}
		{link_sound "exhaust"			""}
		{link_sound "move"				"vehicle/wheels/bike/wheel"}
		{link_sound "brake"				"vehicle/wheels/bike/brake"}
		{link_sound "drop"				"vehicle/wheels/bike/drop"}
	}
	{on "engine_toggle" overload}	;// disables engine toggle for cannons
	{on "engine_on"	overload}		;// disables engine fx and sound for cannons
	
	{on pierce sync
		{vehicle_health_damage_pierce}
	}
	
	{on break
		{if not tagged "exploded"
			{if component "body"
				{tags add "body_break"}
			}
		}
	}
	{on repair
		{if component "body"
			{tags remove "body_break"}
		}
	}

	{on blast_hit
		{if not tagged "exploded"
			{if tagged "body_break"
				{if min_energy 1.5
					{component destroy}
				}
			}
		}
	}

	{on "crew_throw" overload
		{crew_throw_off up 3 0.5 dir 3.5 0.5 turn 0 180 forward 1 rnd_die 1}
	}

	{on "cut_parts"
		(define "cut_part"
			{if rand %1
				{if "crush"
					{tear "piece_medium_steel" bone %0
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}
						{call "check_delete_part"}
					}
				else
					{tear "piece_medium_steel" bone %0
						{impulse up 3 1 dir 3 1 cx 2 1 cy 2 1 rnd_dir 4 no_position}
						{call "check_delete_part"}
					}
				}
			}
		)
		("cut_part" args "part1" 1)
		("cut_part" args "part2" 1)
		("cut_part" args "part4" 1)
		("cut_part" args "part5" 1)
		("cut_part" args "part6" 1)
		("cut_part" args "part7" 1)
		("cut_part" args "part8" 1)
		("cut_part" args "body" 1)
		{delay 0.1 {delete}}
	}

	{on contact
		{if not impregnable
			{if effector "tank"
				{call "crush_damage"}
			else effector "armored_car"
				{call "crush_damage"}
			else effector "truck"
				{call "crush_damage"}
			else effector "car"
				{call "crush_damage"}
			else effector "train" ;// or "railway"
				{call "crush_damage"}
			else effector "airborne"
				{call "crush_damage"}
			else effector "grenade"
				{talk "grenade"}
				{crew_emit}
			}
		}
	}

	{on "crush_damage" overload
		{if effector_velocity 6
			{call_synced "bicycle_crush_sync"}
		else effector_velocity 3
			{component break}
		}
	}

	{on "bicycle_crush_sync"
		{component destroy}
		{if volume "body"
			{set "crush" 1}
			{call "explosion"}
		}
	}

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

;/*===========  Bike Animation Begin  ===========*/
	{on animation_event "drop"
		{play_sound "drop"}
	}
	{on "spawn_no_crew"
		{ani_wind "down" end}
	}
	{on "spawn_with_crew"
		{ani_wind "down" begin}
	}

	{on "event_no_crew"
		{if not velocity 1
			{ani_play "down" +1.0}
		}
	}
	{on "event_with_crew"
		{ani_wind "down" begin}
	}

	(define "update_position"
		{if not operatable
			{if %wind
				{call "spawn_no_crew"}
			else
				{call "event_no_crew"}
			}
		else
			{if %wind
				{call "spawn_with_crew"}
			else
				{call "event_with_crew"}
			}
		}
	)
	{on "update_position_on_spawn"
		("update_position" wind(true))
	}
	(define "update_position_event"
		{on %event
			("update_position" wind(false))
		}
	)
	("update_position_event" event(operatable on))
	("update_position_event" event(operatable off))
	("update_position_event" event(crew in))
	("update_position_event" event(crew out))

	{on engine on
		{play_sound "move" 1}
		{ani_play "move" loop}
		{if not sunlight
			{call "lights_on"}
		}
	}
	{on engine off
		{stop_sound "move"}
		{ani_stop "move"}
		{call "lights_off"}
		{##delay 1 ;// save for when human has animation too 
			{if operatable
				{ani_play "stop" -1.0 resume}
			}
		}
		{if not operatable
			{call "event_no_crew"}
		}
	}

	{on "lights_off"
		{view stop "lights1"}
		{view hide "lights1"}
	}

	{on "update_lights" overload}

	{on "check_speed"
		{if not sunlight
			{if velocity 15
				{view start "lights1"}
				{view show "lights1"}
			else 
				{view stop "lights1"}
				{view hide "lights1"}
			}
		}
	}

	;/*=========== Bike Animation End ===========*/
}