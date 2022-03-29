{"human"
	{inflammation_time 0.35}
	{on spawn
		{add_view	"cigarettesmoke"		"smoke"		"head"}
		{add_view	"drops_water_small2"	"on_water"	"foot3r"}
		{add_view	"drops_water_small2"	"on_water"	"foot3l"}
		{add_view	"drops_water_small3"	"swim"		"foot3r"}
		{add_view	"drops_water_small3"	"swim"		"foot3l"}
		{add_view	"drops_water_small3"	"swim"		"hand2r"}
		{add_view	"drops_water_small3"	"swim"		"hand2l"}
		{add_view	"wash_human_small"		"swim_move"	"head"}
		{add_view	"drops_water_small"		"on_puddle"	"foot3r"}
		{add_view	"drops_water_small"		"on_puddle"	"foot3r"}
		{add_view	"drops_puddle_small"	"on_shallow_water"	"foot3r"}
		{add_view	"drops_puddle_small"	"on_shallow_water"	"foot3l"}

		{add_view	"officer" 				"officer" "head"}
		{add_view	"documents" 			"documents" "head"}

		{add_view	"marker_kill_neutral"		"marker_kill_neutral"		"head" not_manual not_scenario}
		{add_view	"marker_healing"			"marker_healing"			"head" not_manual not_scenario}
		{add_view	"marker_repair"				"marker_repair"				"head" not_manual not_scenario}
		{add_view	"marker_ammo_out"			"marker_ammo_out"			"head" not_manual not_scenario}
		{add_view	"marker_ammo_refill"		"marker_ammo_refill"		"head" not_manual not_scenario}
		{add_view	"marker_personage"			"marker_personage"			"head" not_manual not_scenario}
		{add_view	"marker_personage_acute"	"marker_personage_acute"	"head" not_manual not_scenario}
		{add_view	"marker_veterancy"			"marker_veterancy"			"head" not_manual not_scenario}
		{add_view	"marker_blinded"			"marker_blinded"			"head" not_manual not_scenario}
		{add_view	"selection_linked"			"selection_linked"			"head" not_manual not_scenario}

		{link_sound "crush"				"human/crush"}
		{link_sound "stabbed"			"hit/human/melee"}
		{link_sound "swim"				"human/move/swim"}
		{link_sound "splash"			"hit/water/splash/small"}
		{link_sound "splash_big"		"hit/water/splash/medium"}
		{link_sound "breath"			"human/exhausted/"}
		{link_sound "throw"				"human/anims/throw/"}
		{link_sound "pin"				"weapon/foley/pin_pull"}
		{link_sound "burn"				"fire/loops/medium"}
		{link_sound "burn_scream"		"human/burn"}

		{link_sound "body_fall_heavy"	"human/body_fall/heavy"}
		{link_sound "body_fall_light"	"human/body_fall/light"}

		{link_sound "death_breathe"		"human/death_breathe/"}
		{link_sound "death_choke"		"human/death_choke/"}

		{link_sound "screw_twist"		"human/anims/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anims/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anims/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anims/repair/toolbox_close/"}
		{link_sound "tool_equip"		"human/anims/repair/tool_equip/"}

		{link_sound "pick_up_small"		"human/anims/pickup/small/"}
		{link_sound "crouch"			"human/anims/crouch/"}
		{link_sound "drink_canteen"		"human/anims/drink_canteen/"}
		{link_sound "prone_to_stand"	"human/anims/prone_to_stand/"}
		{link_sound "stand_to_prone"	"human/anims/stand_to_prone/"}
		{link_sound "rest_gun"			"human/anims/rest_gun/"}
		{link_sound "stand_at_attention""human/anims/stand_at_attention/"}
		{link_sound "metal_footstep"	"human/move/normal/metal"}
		{link_sound "metal_hand"		"human/anims/metal_hand"}
		{link_sound "shovel_ground"	"human/anims/dig/shovel/ground"}
		{link_sound "shovel_snow"	"human/anims/dig/shovel/snow"}
		{link_sound "pickaxe_ground"	"human/anims/dig/pickaxe/ground"}
		{link_sound "construct_mine"	"human/anims/construct_mine"}
		{link_sound "construct_sandbag"	"human/anims/construct_sandbag"}
		(include "human_texmods.inc")

		(mod "mp" 							;// fix for conquest. Stops infantry from being of fire at spawn, if they were on fire but not dead at end of last mission.
			{if able "burning"
				{able "burning" 0}
				{able select 1}
			}
		)
		(mod not "mp"
			{if able "burning"
				{call "add_burn_fx"}
				{view start "burn_fire"}
			}
		)

		{delay 0.1
			{if linked "airborne"
				{volumes disable blast}		;// stops crew from being killed by AA blast energy
			}
		}
	}

	(define "knock_out"
		{if not water_level -0.1
			{knockdown %0 %1}
		}
	)

	{on contact sync
		{if not impregnable
			{if not volume "ram"
				{kill_flags reset}
				{volumes disable contact}
				{delay 2
					{volumes enable contact}
				}
				{if effector "cannon"
					; do nothing
				else effector "vehicle"
					{if personage
						{able "personage" 0}
					}
				}
				{if effector "tank"
					{call "crush"}
					{health_damage_count 500 {effects "" "hit" "damage" "die" "die"}}
					("knock_out" args 10 2)	;// time unconsious. 10 ±2 seconds
				else effector "marine"
					{health_damage_count 80 {effects "" "hit" "damage" "die" "die"}}
				else effector "cannon"
					{health_damage_count 5 {effects "" "hit" "damage" "die" "die"}}
				else effector "vehicle"
					{call "crush"}
					{health_damage_count 200 {effects "" "hit" "damage" "die" "die"}}
					("knock_out" args 5 2)	;// time unconsious. 5 ±2 seconds
				else effector "knife"
					{if contact_velocity 10
						{play_sound "stabbed"}
						{health_damage_count 1000
							{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
						}
					}
				(define "human_health"
					{health_damage_count %c
						{effects "" "hit" "damage" "die" "die"}
					}
				)
				else effector "axe"
					{if contact_velocity 5
						("human_health" c(500))
					}
				(define "contact_part"
				else effector %e
					{if contact_velocity %v
						{if difficulty "easy"
							{if user_control
								("human_health" c(%ud))
							else
								("human_health" c(%d))
							}
						else
							("human_health" c(%d))
						}
						("human_health" c(%d))
					}
				)
				("contact_part" e("building_part")	v(3)	ud(20)	d(60))
				("contact_part" e("big part")		v(3)	ud(20)	d(60))
				("contact_part" e("medium part")	v(6)	ud(10)	d(30))
				("contact_part" e("small part")		v(10)	ud(3)	d(20))
				else effector "chicken"
					{health_damage_count 0
						{effects "" "hit" "hit" "hit" "hit"}
					}
				else effector "wire"
					{health_damage_count 20
						{effects "" "hit" "damage" "die" "die"}
					}
				else effector "fx_piece_flame"
					{if not dead
						("human_health" c(10))
						{able select 0}
						{drop_orders}
						{weapon_work "hand_right" 0}
					}
				}
			}
		}
	}

	{on bullet_hit
		{kill_flags reset}
		{signal hit 5}
		{if stuff "auto"
			{call "process_bullet_hit"}
		else stuff "shell fg"
			{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "rocketlauncher"
			{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "rifle_grenade_at"
			{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "bullet"
			{if volume_armored
				{bullet_detonate}
				{spawn "helmet_hit_bul"}
			}
			{call "process_bullet_hit"}
		else
			{call "process_bullet_hit"}
		}
	}
	{on "blow_effect"
		{if not name "knife"
			{start_sound "human/blow"}
		}
	}
	{on "blow_opponent_effect"
		{if name "head"
			{spawn "blood_small" "head"}
		}
	}
	{on blow opponent sync
		{if name "knife"
			{play_sound "stabbed"}
			{health_damage_blow
				{effects "" "hit" "hit" "die_from_knife" "die_from_knife"}
			}
		else
			{health_damage_blow
				{effects "" "hit" "hit" "die" "die"}
			}
		}
	}

	{on "process_bullet_hit" sync
		{if hit_side front
			{kill_flags front}
		else hit_side back
			{kill_flags back}
		else
			{kill_flags front back}
		}

		{if velocity 7
			{kill_flags run}
		else velocity 0.1
			{kill_flags go}
		}
		{kill_flags piercing}
		{if	stuff "rifle"
			{kill_flags rifle}
		}
		{if	stuff "mgun"
			{kill_flags mgun}
		}
		{if	stuff "smg"
			{kill_flags smg}
		}
		{if	stuff "pistol"
			{kill_flags pistol}
		}

		{health_damage_pierce
			{effects
				"hit-scream"
				"hit-light"
				"hit-heavy"
				"die"
				"hit-explosion"
				"throw-off"
				"throw-off-and-die"
			}
			{explosive_treshold 70} ;// value = amount of damage done to human
			{table	;// table for "throw_off" impluse
			;//{ , impulse}
				{30 	1	}
				{200	2.5	}
				{500	3	}
				{5000	5	}
			}
		}
	}

	{on blast_hit overload sync
		{if not dead
			{if min_energy 1.25
				{call "unhealable"}
			}
		}
		{if stuff "grenade"
			{if min_energy 0.95
				("human_health" c(75))
			}
		}
		{if stuff "rifle"		;// Rifle grenades. Tag from weapon not ammo.
			{if min_energy 0.95
				("human_health" c(75))
			}
		}
		{if stuff "mine"
			{if min_energy 0.75
				("human_health" c(120))
			else min_energy 0.45
				("human_health" c(60))
			}
		}
		{if min_energy 2.6
			("human_health" c(350))
		else min_energy 1.9
			("human_health" c(225))
		else min_energy 1.2
			("human_health" c(100))
		}

		{kill_flags reset}
		{if hit_side front
			{kill_flags front}
		else hit_side back
			{kill_flags back}
		else
			{kill_flags front back}
		}
		{kill_flags blast}

		{health_damage_blast
			{effects
				"hit-scream"
				"hit-light"
				"hit-heavy"
				"die"
				"hit-explosion"
				"throw-off"
				"throw-off-and-die"
			}
			{table	;// table for "throw_off" impluse
			;//{blast energy, impulse}
				{1.1	0.5	}
				{2.0	1	}
				{10		2	}
				{50		3	}
			}
		}
	}

	{on "die_throw_high"
		{set "die_after_throw" 1}
		{call "personage_check"}
		{spawn "blood_small"}
		{call "die_scream"}
		{call "throw_high"}
	}

	{on "hit-scream"
		{if not "talk"
			{set "talk" 1}
			{talk "injuring"}
			{delay 10 2
				{set "talk" 0}
			}
		}
	}

	{on "hit-light"
		{if not dead
			{spawn "blood_small"}
		}
	}

	{on "hit-heavy"
		{spawn "blood_medium"}
	}

	{on "hit-explosion"
		{if personage
			{able "personage" 0}
		}
		{if tagged "no_explosion"
			{call "die"}
		else
			{call "die_scream"}
			{call "explosion"}
		}
	}

	{on "throw-off"
		{set "die_after_throw" 0}
		{if not stuff "no_throw"
			{if not linked "airborne"
				{call "throw_high"}
			}
		}
	}

	{on "throw-off-and-die"
		;//{start_sound "human/talk/impulse"} ;//?
		{set "die_after_throw" 1}
		{call "die_scream"}
		{if not stuff "no_throw"
			{if not linked "airborne"
				{call "personage_check"}
				{call "throw_high"}
			}
		else
			{if stuff "shell"
				{call "unhealable"}
				{call "die"}
				{if not stuff "auto"
					{call "explosion"}
				}
			}
		}
	}

	{on "hit"
		{call "hit-scream"}
	}

	{on "damage"
		{call "hit"}
	}

	{on "throw_high"
		{if senseless
			{if not dead
				{call "die"}
			}
		else
			{if not dead
				{if linked "vehicle"
					{if "die_after_throw"
						{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 die force}
					else
						{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 force}
					}
				else
					{if "die_after_throw"
						{throw_off up 3 0.8 dir 3.5 0.5 forward 0 0 die}
					else
						{if not linked "windowed"
							{throw_off up 3 0.8 dir 3.5 0.5 forward 0 0}
						}
					}
				}
			else
				{call "explosion"}
			}
		}
	}

	{on "throw_off_end"				;// from {crew_throw_off} in vehicle.inc and cannon.inc
		{if "not_knocked"
			;// do nothing
		else
			;//{start_sound "human/talk/impulse"} ;//?
			{##if not user_control
				{health_damage_count 50
					{effects "" "hit" "damage" "die" "die"}
				}
			}
			("knock_out" args 12 3)	;// time unconsious. 12 ±3 seconds
		}
	}

	{on "throw_off_end_die"		;// from {crew_throw_off} in vehicle.inc and cannon.inc
		;//{start_sound "human/talk/impulse"} ;//?
		{call "die"}
	}

	{on "throw_off_from_tower"
		{throw_off up 1 forward 2 die force}
		;//{start_sound "human/talk/impulse"} ;//?
	}

	{on "throw_off_from_ladder"
		{throw_off up 1 forward -2 die force}
		;//{start_sound "human/talk/impulse"} ;//?
	}

	{on "throw_off_from_ship"
		{throw_off up 4 dir 3 1 die force}
		;//{start_sound "human/talk/impulse"} ;//?
	}

	{on "throw_off_from_vehicle"
		;//{start_sound "human/talk/impulse"} ;//?
		{throw_off up 1 0.5 dir 1 turn 0 360 force die}
	}

	{on "linker_simulation"
		{if effector "airborne"
			;// do nothing
		else effector "cannon"
			;// do nothing
		else altitude 3
			{throw_off up 1 forward 2 die force}
		}
	}

	{on "unhealable"
		{tags add "unhealable"}	
		{tags add "no_revive"}
		{delay 0.5							;// removes tag incase blastwave doesn't kill human
			{tags remove "no_revive"}
		}
	}

	{on "personage_check"
		{if not user_control
			{able "personage" 0}
		else swimming
			{able "personage" 0}
		else burned
			{able "personage" 0}
		else tagged "crush"
			{able "personage" 0}
		else tagged "no_revive"
			{able "personage" 0}
			{tags remove "no_revive"}
		else 
			{if rand 0.5
				{call_synced "mp_personage_0"}
			}
		}
	}

	{on "mp_personage_0"
		(mod "mp"
			{able "personage" 0}
		)
	}

	{on "floating"			;// dead and floating. Currently does not work. Revisit.
	}

	{on "die"
		{view stop "officer"}
		{view stop "documents"}
		{call "personage_check"}
		{if linked "airborne"
			{call "delete"}
		}
		{if not dead
			{spawn "blood_small"}
			{if linked
				{if linked "shipflak"
					{call "throw_off_from_ship"}
				else linked "doublecolt"
					{call "throw_off_from_ship"}
				else linked "car"
					{if place "driver"
						{throw_off up 1 forward 1 turn -90 die force rotate_to_dir}
					else place "commander"
						{throw_off up 1 forward 1 turn +90 die force rotate_to_dir}
					else
						{call "die_with_blood"}
					}
				else altitude 2
					{if boarding
						{call "throw_off_from_ladder"}
					else
						{call "throw_off_from_tower"}
					}
				else linked "cannon"
					{call "die_with_blood"}
				else linked "vehicle"
					{call "throw_off_from_vehicle"}
				else
					{call "die_with_blood"}
				}
			else swimming
				{call "die_without_blood"}
				{call "floating"}
			else
				{call "die_with_blood"}
			}
		}
	}

	{on "die_with_blood"
		;{if not senseless
			{if not able "personage"
				{if not burned
					{spawn "blood"}							;// blood splatter ground texture
					{delay 2
						{spawn "bloodstain" "basis" x}		;// spawns a pool of blood that spreads
					}
				}
			}
		;}
		{call "die_without_blood"}
	}

	{on "die_without_blood"
		{view pause "swim"}
		{if not "die_from_knife"
			{call "die_scream"}
		}
		{if not kill_flags blast
			{kill_flags piercing}
		}
		{die}
		{delay 5
			{volumes enable contact}
		}
	}

	{on "die_scream"
		{if not "die_sound"
			{set "die_sound" 1}
			{talk "death_cry"}
			{signal mandie 5}
		}
	}

	{on "die_from_knife"
		{set "die_from_knife" 1}
		{call "die"}
	}

	{on ground_hit
		{if linked "paratrooper_attach"
			{tags remove "can_die"}
			{unlink}						;// kicks human out of parachute when reaching ground
			{set "not_knocked" 1}			;// helps stops {knock_down} call when thrown off from plane
			{delay 1.3						;// stops sliding after landing on ground. forces soldier to ground
				{physics_work 0}
				{delay 0
					{physics_work 1}
					{throw_off up 0.5 0.2 forward 1 0.5}
				}
			}
		else tagged "can_die"
			{call "die"}
			{kill_delay "parachute"}
			{tags remove "can_die"}
			{tags remove "eject"}
		else
			{if min_speed 10
				{spawn "blood_medium" "basis" x}	;// Fall and hit the ground.
				{spawn "blood"}						;// blood splatter ground texture
			}
		}
	}

	(define "piece_explosion"
		{spawn %0 %1
			{impulse	up 1 0.5 dir 8 4
						cx 0 12 cy 0 12
						fx 0 60 fy 0 60 fz 80 40
			}
		}
	)

	(define "spawn_pieces"
		;//left hand
		{if rand 0.2
			(%0 args "#hand00" "hand1l")
		else rand 0.2
			(%0 args "#hand01" "hand1l")
		else rand 0.2
			(%0 args "#hand02" "hand1l")
		}
		;//right hand
		{if rand 0.2
			(%0 args "#hand00" "hand1r")
		else rand 0.2
			(%0 args "#hand01" "hand1r")
		else rand 0.2
			(%0 args "#hand02" "hand1r")
		}

		;//left foot
		{if rand 0.3
			(%0 args "#leg00" "foot1l")
		}
		;//right foot
		{if rand 0.3
			(%0 args "#leg00" "foot1r")
		}

		;//head
		{if rand 0.3
			(%0 args "#head00" "head")
		else rand 0.3
			(%0 args "#head01" "head")
		}
	)

	{on "explosion"
		{spawn "blood_medium"}
		;("spawn_pieces" args "piece_explosion")
		;{call "delete"}
	}

	{on "crush"
		{spawn "blood_medium"}
		{play_sound "crush"}
		{call "unhealable"}
	}

	{on "delete"
		{if not dead
			{stat_notify die}
		}
		{delete}
	}

	{on "burn_volume"
		{if volume "body"
			{call "_burn"}
		}
	}

	{on "_burn"
		{if not burned
			{able "burning" 1}			;// causes unit to act uncontrolable
			(define "try_get_off"		;// unlinks unit from vehicles
				{delay %0 0.5
					{unlink}
				}
			)
			("try_get_off" args 0.5)
			("try_get_off" args 2.0)
			("try_get_off" args 3.0)
			("try_get_off" args 4.0)
			("try_get_off" args 5.0)

			{call "add_burn_fx"}
			{delay_effect 0.5 0.2 "burn_scream"}	;// calls burn_scream event below and loops

			(define "burn_damage"					;// causes increasing damage to human health over time
				{delay %t "burn_damage"
					{if not dead
						{if able "burning"
							("human_health" c(%c))
							{fire radius 1 time 1 heating 0.75 follow}	;// adds heating to unit (potential to set other items on fire due to proximity)
						}
						{tags add "no_revive"}
						{tex_morph "burned" 5}

					}
				}
			)
			{if not dead
				{able select 0}
				{drop_orders}

				("burn_damage" t(0) c(100))
				("burn_damage" t(1) c(200))
				("burn_damage" t(2) c(300))
				("burn_damage" t(3) c(400))
				("burn_damage" t(4) c(500))
			}

			{delay 20
				{view stop "burn_fire"}		;// stops burning fx
				{stop_sound "burn"}
				{able "burning" 0}			;// stops uncontrolable actions (keep incase friendly is set on fire and is not damaged/killed)
				{delay 1.0
					{call "stop_burn"}
				}
				{if not dead
					{able select 1}
				}
			}
			{burn time 20}					;// Required! Without it, humans die instantly when on fire
		}
	}

	{on "add_burn_fx"
		{play_sound "burn" 1}
		{add_view "fire_dead" "burn_fire" "body"}
		{view start "burn_fire"}
	}

	{on "burn_scream"
		{if not dead
			{play_sound "burn_scream"}
			{if not senseless
				{if not "quench"
					{delay_effect 1.25 0.5 "burn_scream"}		;// calls own event again (loops)
				else
					{view stop "burn_fire"}						;// stops burning fx
					{set "quench" 0}							;// allows unit to be able to burn again
					{able "burning" 0}							;// stops uncontrolable actions
				}
			}
		}
	}

	{on "stop_burn"
		{stop_sound "breath"}
		{if burned
			{burn stop_retry}
			{set "quench" 1}			;// stops "burn_scream" loop
			{delay 2					;// quench 0 in "burn_scream" not working. Backup code.
				{set "quench" 0}
			}
		}
	}

	{on "smoke"
		{smoke}
	}

	{on "smoking"
		{view start "smoke"}
		{delay 0.3 0.1
			{view pause "smoke"}
		}
	}

	{on "link_weapon"
		{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
			{with_effector
				{call "link_human"}
			}
		}
	}

	{on "unlink_weapon"
		{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
			{with_effector
				{call "unlink_human"}
			}
		}
	}

	{on fire "hand_right"
		{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
			{with_effector
				{call "fire"}
			}
		}
	}

	{on "reload"
		{if effector "stuff weapon"
			{set "delete_parts" 1}				;// defined in dummy.inc hides torn magazine after delay.
			{with_effector
				{call "weapon_reload"}			;// defined in stuff.inc
			}
		}
	}

	(define "terrain_fx_human"					;// adds fx for human movement on water terrains
		{on terrain_fx %terrain enter
			{if not swimming
				{view start "on_%fx"}
			}
			{if burned
				{delay 0.5
					{call "%effect"}				;// stops human burn damage and fire fx
				}
			}
		}
		{on terrain_fx %terrain leave
			{view pause "on_%fx"}
		}
	)
	("terrain_fx_human" terrain("water")			fx(water)			effect(stop_burn))
	("terrain_fx_human" terrain("shallow_water")	fx(shallow_water)	effect(stop_burn))
	("terrain_fx_human" terrain("puddle")			fx(puddle)			effect())
	("terrain_fx_human" terrain("mud")				fx(mud)				effect())

	{on "diving"			;// transition from walking in shallow water to jumping/diving into water or deep water terrains
		{delay 0.3
			{spawn "spherewater_big"}
		}
	}

	{on swim on				;// swimming movement mode
		{view pause "on_water"}
		{view start "swim"}
		{call "stop_burn"}
		{kill_delay "after_swim"}
	}

	{on swim off			;// swimming movement mode
		{delay 1.5 "after_swim"
			{view pause "swim"}
		}
	}

	{on move on
		{if swimming
			{view start "swim_move"}
			{play_sound "swim" 1}
		}
	}

	{on move off
		{view pause "swim_move"}
		{call "stop_move_sounds"}
	}

	(define "play_move_sound"
		{if terrain_fx "road"
			{start_sound "human/move/%0/road/" 1}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "rock"
			{start_sound "human/move/%0/road/" 1}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "bridge"
			{start_sound "human/move/%0/road/" 1}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "bridge_wood"
			{start_sound "human/move/%0/wood/" 1}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "bridge_steel"
			{start_sound "human/move/%0/metal/" 1}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "country_road"
			{start_sound "human/move/%0/gear_rattle/" 1}
			{if rain
				{start_sound "human/move/%0/mud/" 1}
				{if not lying {spawn "gritrun_foot_mud" scale 0.75}}
			else
				{start_sound "human/move/%0/ground/" 1}
				{spawn "dustrun_foot_ground"}
			}
		else terrain_fx "mud"
			{start_sound "human/move/%0/mud/" 1}
			{if not lying {spawn "gritrun_foot_mud" scale 0.75}}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "ice"
			{start_sound "human/move/%0/ice/" 1}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "snow"
			{start_sound "human/move/%0/snow/" 1}
			{if not rain {spawn "dustrun_foot_snow"}}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "sand"
			{start_sound "human/move/%0/sand/" 1}
			{if not rain {spawn "dustrun_foot_sand"}}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "grass"
			{start_sound "human/move/%0/grass/" 1}
			{if not rain {spawn "dustrun_foot_ground" scale 0.1}}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "water"
			{start_sound "human/move/%0/shallow_water/" 1}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "shallow_water"
			{start_sound "human/move/%0/shallow_water/" 1}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "puddle"
			{start_sound "human/move/%0/puddle/" 1}
			{start_sound "human/move/%0/gear_rattle/" 1}
		else terrain_fx "ground"
			{start_sound "human/move/%0/gear_rattle/" 1}
			{if rain
				{start_sound "human/move/%0/mud/" 1}
				{if not lying {spawn "gritrun_foot_mud" scale 0.75}}
			else
				{start_sound "human/move/%0/ground/" 1}
				{spawn "dustrun_foot_ground"}
			}

		}
	)

	{on "stop_move_sounds"
		{stop_sound "swim"}
		{stop_sound "breath"}
		{stop_sound "wade"}
		{set "fast_move_mode" 0}
	}

	{on movement_mode_changed
		{call "stop_move_sounds"}
		{if name "fast"
			{if not lying
				("play_move_sound" args fast start)
				{play_sound "breath" 1}
				{set "fast_move_mode" 1}
			}
		}
		{if lying									;// give human chance to put out fire if they go prone/lie and move
			{if burned
				{delay 1.75 0.5
					{call "stop_burn"}				;// stops human burn damage and fire fx
				}
			}
		}
	}

	(define "play_leg_sound"
		{if "fast_move_mode"
			("play_move_sound" args fast %0)
		else lying
			("play_move_sound" args lying %0)
		else
			("play_move_sound" args normal %0)
		}
	)

	{on animation_event "arm_right"				;// event created by animation
		{play_sound "throw"}
	}
	{on animation_event "pin"			;// event created by animation
		{play_sound "pin"}
	}
	{on animation_event "leg_left"				;// event created by animation
		("play_leg_sound" args left)
	}
	{on animation_event "leg_right"				;// event created by animation
		("play_leg_sound" args right)
	}
	{on animation_event "body_fall_heavy"		;// event created by animation
		{play_sound "body_fall_heavy"}
	}
	{on animation_event "body_fall_light"		;// event created by animation
		{play_sound "body_fall_light"}
	}
	{on animation_event "screw_twist"			;// event created by animation
		{play_sound "screw_twist"}
	}
	{on animation_event "wrench_turn"			;// event created by animation
		{play_sound "wrench_turn"}
	}
	{on animation_event "toolbox_open"			;// event created by animation
		{play_sound "toolbox_open"}
	}
	{on animation_event "toolbox_close"			;// event created by animation
		{play_sound "toolbox_close"}
	}
	{on animation_event "tool_equip"			;// event created by animation
		{play_sound "tool_equip"}
	}
	{on animation_event "pick_up_small"			;// event created by animation
		{play_sound "pick_up_small"}
	}
	{on animation_event "crouch"				;// event created by animation
		{play_sound "crouch"}
	}
	{on animation_event "drink_canteen"			;// event created by animation
		{play_sound "drink_canteen"}
	}
	{on animation_event "prone_to_stand"		;// event created by animation
		{play_sound "prone_to_stand"}
	}
	{on animation_event "stand_to_prone"		;// event created by animation
		{play_sound "stand_to_prone"}
	}
	{on animation_event "rest_gun"				;// event created by animation
		{play_sound "rest_gun"}
	}
	{on animation_event "stand_at_attention"	;// event created by animation
		{play_sound "stand_at_attention"}
	}
	{on animation_event "splash"				;// event created by animation
		{play_sound "splash"}
	}
	{on animation_event "swim"					;// event created by animation
		{play_sound "swim"}
	}
	{on animation_event "burn_scream"			;// event created by animation
		{play_sound "burn_scream"}
	}
	{on animation_event "metal_footstep"		;// event created by animation
		{play_sound "metal_footstep"}
	}
	{on animation_event "metal_hand"			;// event created by animation
		{play_sound "metal_hand"}
	}
	{on animation_event "shovel"			;// event created by animation
	  {if terrain_fx "snow"
			{play_sound "shovel_snow"}

			else terrain_fx "sand"
			{play_sound "shovel_snow"}

			else
			{play_sound "shovel_ground"}
		}
	}
	{on animation_event "pickaxe"			;// event created by animation
		{play_sound "pickaxe_ground"}
	}
	{on animation_event "construct_mine"			;// event created by animation
		{play_sound "construct_mine"}
	}
	{on animation_event "construct_sandbag"			;// event created by animation
		{play_sound "construct_sandbag"}
	}

	{on "falldown"
		{if altitude 3
			{throw_off up 1 forward 0.01 die force}
		else altitude 1.25 					;// lower values will cause humans to fall when building trenches
			{throw_off up 1 forward 0.01 force}
		}
	}

	{on board in							;// boarding a vehicle
		{view pause "swim"}
		{if linked "airborne"
			{volumes disable blast}					;// stops crew from being killed by AA blast energy
		}
	}

	{on board out							;// exiting a vehicle
		{if linked "airborne"
			{delay 0.01
				(mod not "mp" {call "eject"})
				{volumes disable contact}			;// stops humans from "colliding" with plane when ejecting.
				{volumes enable bullet}
				{delay 1 {volumes enable contact blast}}
			}
		}
	}

	{on "eject"								;// human leaving airbone unit
		{tags add "can_die"}
		{if altitude 1
			{throw_off up 2 forward 0.01}
			{delay 0.4 0.1 "parachute"
				{if altitude 4
					{tags add "eject"}
					{spawn "paratrooper_attach" offset 205 -10 -534}
				}
			}
		else
			;{tags remove "can_die"}
			{throw_on_ground}
		}
	}

	{on "kill_neutral"
		{view start ally neutral "marker_kill_neutral"}
		{delay 5.0
			{view pause "marker_kill_neutral"}
		}
	}

	{on "start_healing"
		{view start ally neutral "marker_healing"}
	}

	{on "stop_healing"
		{view pause "marker_healing"}
	}

	{on "start_repair"
		{view start ally neutral "marker_repair"}
	}

	{on "stop_repair"
		{view pause "marker_repair"}
	}

	{on "start_ammo_out"
		{view start ally neutral "marker_ammo_out"}
	}

	{on "stop_ammo_out"
		{view pause "marker_ammo_out"}
	}

	{on "start_ammo_refill"
		{view start ally neutral "marker_ammo_refill"}
		{delay 2.5
			{view pause "marker_ammo_refill"}
		}
	}

	{on "start_personage"
		{view pause "marker_personage_acute"}
		{view start ally neutral "marker_personage"}
	}

	{on "stop_personage"
		{view pause "marker_personage"}
		{view pause "marker_personage_acute"}
	}

	{on "start_personage_acute"
		{view pause "marker_personage"}
		{view start ally neutral "marker_personage_acute"}
	}

	{on "start_veterancy"
		{view start ally neutral "marker_veterancy"}
		{delay 3.5
			{view pause "marker_veterancy"}
		}
	}

	{on "stop_veterancy"
		{view pause "marker_veterancy"}
	}

	{on "hide_veterancy"
		{view hide "marker_veterancy"}
	}

	{on "start_blinded"
		{view start ally neutral "marker_blinded"}
	}

	{on "stop_blinded"
		{view pause "marker_blinded"}
	}

	{on "capture"
		{tags add "capturer"}
	}

	{on "officer_mark"
		{view start "officer"}
	}

	{on "documents"
		{view start "documents"}
	}
}
