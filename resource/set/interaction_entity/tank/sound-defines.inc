;/*=========== German Vehicles Begin ===========*/

(define "kubel_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/kubel/start"}
		{link_sound "engine_stop"		"vehicle/engine/kubel/stop"}
		{link_sound "engine_idle"		"vehicle/engine/kubel/idle"}
		{link_sound "engine_full"		"vehicle/engine/kubel/full"}
		{link_sound "exhaust"			"vehicle/engine/kubel/exhaust"}
		{link_sound "move"			"vehicle/wheels/car"}
	}
)
(define "r12_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/r12/start"}
		{link_sound "engine_stop"		"vehicle/engine/r12/stop"}
		{link_sound "engine_idle"		"vehicle/engine/r12/idle"}
		{link_sound "engine_full"		"vehicle/engine/r12/full"}
		{link_sound "exhaust"			"vehicle/engine/r12/exhaust"}
		{link_sound "move"			"vehicle/wheels/bike"}
	}
)
(define "opel_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/blitz/start"}
		{link_sound "engine_stop"		"vehicle/engine/blitz/stop"}
		{link_sound "engine_idle"		"vehicle/engine/blitz/idle"}
		{link_sound "engine_full"		"vehicle/engine/blitz/full"}
		{link_sound "exhaust"			"vehicle/engine/blitz/exhaust"}
		{link_sound "move"			"vehicle/wheels/truck"}
		{link_sound "brake"			"vehicle/wheels/brake"}
		{link_sound "rotate_turret"		"vehicle/turret/cannon/small"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/small"}

		{link_sound "open_left"			"vehicle/doors/blitz/open_left"}
		{link_sound "open_right"		"vehicle/doors/blitz/open_right"}
		{link_sound "open_rear"			"vehicle/doors/blitz/open_rear"}
		{link_sound "close_rear"		"vehicle/doors/blitz/close_rear"}
		{link_sound "open_radio"		"vehicle/doors/blitz/open_radio"}
	}
)

(define "opel_maultier_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/blitz/start"}
		{link_sound "engine_stop"		"vehicle/engine/blitz/stop"}
		{link_sound "engine_idle"		"vehicle/engine/blitz/idle"}
		{link_sound "engine_full"		"vehicle/engine/blitz/full"}
		{link_sound "exhaust"			"vehicle/engine/blitz/exhaust"}
		{link_sound "move"			"vehicle/wheels/halftrack"}
		{link_sound "brake"			"vehicle/wheels/brake"}

		{link_sound "open_left"			"vehicle/doors/blitz/open_left"}
		{link_sound "open_right"		"vehicle/doors/blitz/open_right"}
		{link_sound "open_rear"			"vehicle/doors/blitz/open_rear"}
		{link_sound "close_rear"		"vehicle/doors/blitz/close_rear"}
	}
)

(define "hanomag_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz251/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz251/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz251/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz251/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251/exhaust"}
		{link_sound "move"			"vehicle/tracks/sdkfz251/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}
	}
)

(define "sdkfz222_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz222/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz222/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz222/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz222/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz222/exhaust"}
		{link_sound "move"			"vehicle/wheels/armored_car"}
		{link_sound "brake"			"vehicle/wheels/brake"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}

		{link_sound "wheel_ground"  		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_grass" 		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_water" 		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_puddle" 		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_mud" 		"vehicle/wheels/overlay/wheel_overlay_mud_snow"}
		{link_sound "wheel_snow" 		"vehicle/wheels/overlay/wheel_overlay_mud_snow"}
		{link_sound "wheel_road" 		"vehicle/wheels/overlay/wheel_overlay_road"}
		{link_sound "wheel_rock" 		"vehicle/wheels/overlay/wheel_overlay_rock"}
		{link_sound "wheel_wood" 		"vehicle/wheels/overlay/wheel_overlay_wood"}
	}
)

(define "sdkfz232_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz232/start"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz232/stop"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz232/idle"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz232/full"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz232/exhaust"}
		{link_sound "move"			"vehicle/wheels/armored_car"}
		{link_sound "brake"			"vehicle/wheels/brake"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}

		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}		
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}

		{link_sound "wheel_ground"  		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_grass" 		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_water" 		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_puddle" 		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_mud" 		"vehicle/wheels/overlay/wheel_overlay_mud_snow"}
		{link_sound "wheel_snow" 		"vehicle/wheels/overlay/wheel_overlay_mud_snow"}
		{link_sound "wheel_road" 		"vehicle/wheels/overlay/wheel_overlay_road"}
		{link_sound "wheel_rock" 		"vehicle/wheels/overlay/wheel_overlay_rock"}
		{link_sound "wheel_wood" 		"vehicle/wheels/overlay/wheel_overlay_wood"}
	}
)

(define "sdkfz234_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "move"			"vehicle/wheels/armored_car"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz234/start"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz234/full"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz234/stop"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234/exhaust"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz234/idle"}
		{link_sound "brake"			"vehicle/wheels/brake"}

		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}

		{link_sound "wheel_ground"  		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_grass" 		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_water" 		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_puddle" 		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_mud" 		"vehicle/wheels/overlay/wheel_overlay_mud_snow"}
		{link_sound "wheel_snow" 		"vehicle/wheels/overlay/wheel_overlay_mud_snow"}
		{link_sound "wheel_road" 		"vehicle/wheels/overlay/wheel_overlay_road"}
		{link_sound "wheel_rock" 		"vehicle/wheels/overlay/wheel_overlay_rock"}
		{link_sound "wheel_wood" 		"vehicle/wheels/overlay/wheel_overlay_wood"}
	}
)
(define "panhard_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "move"			"vehicle/wheels/armored_car"}
		{link_sound "engine_start"		"vehicle/engine/panhard/start"}
		{link_sound "engine_full"		"vehicle/engine/panhard/full"}
		{link_sound "engine_stop"		"vehicle/engine/panhard/stop"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}
		{link_sound "exhaust"			"vehicle/engine/panhard/exhaust"}
		{link_sound "engine_idle"		"vehicle/engine/panhard/idle"}
		{link_sound "brake"			"vehicle/wheels/brake"}

		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}

		{link_sound "wheel_ground"  		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_grass" 		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_water" 		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_puddle" 		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_mud" 		"vehicle/wheels/overlay/wheel_overlay_mud_snow"}
		{link_sound "wheel_snow" 		"vehicle/wheels/overlay/wheel_overlay_mud_snow"}
		{link_sound "wheel_road" 		"vehicle/wheels/overlay/wheel_overlay_road"}
		{link_sound "wheel_rock" 		"vehicle/wheels/overlay/wheel_overlay_rock"}
		{link_sound "wheel_wood" 		"vehicle/wheels/overlay/wheel_overlay_wood"}
	}
)
(define "sdkfz302_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/sdkfz302"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz302/start"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz302/full"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz302/stop"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz302/exhaust"}
		;{link_sound "engine_idle"		"vehicle/engine/sdkfz302/idle"}

		{link_sound "wheel_ground"  		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_grass" 		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_water" 		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_puddle" 		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_mud" 		"vehicle/cannon_roll/overlays/cannon_overlay_snow"}
		{link_sound "wheel_snow" 		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_road" 		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_rock" 		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_wood" 		"vehicle/cannon_roll/overlays/cannon_overlay_wood"}
	}
)

(define "sdkfz303_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/sdkfz302"}
		{link_sound "engine_start"		"vehicle/engine/sdkfz303/start"}
		{link_sound "engine_full"		"vehicle/engine/sdkfz303/full"}
		{link_sound "engine_stop"		"vehicle/engine/sdkfz303/stop"}
		{link_sound "exhaust"			"vehicle/engine/sdkfz303/exhaust"}
		{link_sound "engine_idle"		"vehicle/engine/sdkfz303/idle"}

		{link_sound "wheel_ground"  		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_grass" 		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_water" 		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_puddle" 		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_mud" 		"vehicle/cannon_roll/overlays/cannon_overlay_snow"}
		{link_sound "wheel_snow" 		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_road" 		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_rock" 		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_wood" 		"vehicle/cannon_roll/overlays/cannon_overlay_wood"}
	}
)

(define "pz1_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_start"		"vehicle/engine/pz1/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz1/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz1/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz1/full"}
		{link_sound "exhaust"			"vehicle/engine/pz1/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz1/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}

		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
	}
)
(define "pz2_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_start"		"vehicle/engine/pz2/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz2/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz2/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz2/full"}
		{link_sound "exhaust"			"vehicle/engine/pz2/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz2/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}

		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
	}
)
(define "pz38_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_start"		"vehicle/engine/hetzer/start"}
		{link_sound "engine_stop"		"vehicle/engine/hetzer/stop"}
		{link_sound "engine_idle"		"vehicle/engine/hetzer/idle"}
		{link_sound "engine_full"		"vehicle/engine/hetzer/full"}
		{link_sound "exhaust"			"vehicle/engine/hetzer/exhaust"}
		{link_sound "move"			"vehicle/tracks/hetzer/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}

		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
	}
)
(define "pz3_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz3/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz3/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz3/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz3/full"}
		{link_sound "exhaust"			"vehicle/engine/pz3/exhaust"}
		{link_sound "move"				"vehicle/tracks/pz3/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}

		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
	}
)
(define "pz4_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz4/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz4/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz4/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz4/full"}
		{link_sound "exhaust"			"vehicle/engine/pz4/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz4/"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
;-------------------------------	INTERIOR SOUNDS		--------------------------------------
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/electric/electric_light"}
	}
)
(define "pz5_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz5/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz5/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz5/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz5/full"}
		{link_sound "exhaust"			"vehicle/engine/pz5/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz5/"}
		{link_sound "rotate_turret"		"vehicle/turret/hydraulic/hydraulic_heavy"}
;-------------------------------	INTERIOR SOUNDS		--------------------------------------
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start_INT"		"vehicle/engine/pz5/INT/start/"}
		{link_sound "engine_stop_INT"		"vehicle/engine/pz5/INT/stop/"}
		{link_sound "engine_idle_INT"		"vehicle/engine/pz5/INT/idle/"}
		{link_sound "engine_full_INT"		"vehicle/engine/pz5/INT/full/"}
		{link_sound "exhaust_INT"		"vehicle/engine/pz5/INT/exhaust/"}
		{link_sound "move_INT"			"vehicle/tracks/INT/pz5_track_INT"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/hydraulic/hydraulic_heavy"}
	}
)
(define "pz6_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz6/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz6/"}
		{link_sound "rotate_turret"		"vehicle/turret/hydraulic/hydraulic_heavy"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/hydraulic/hydraulic_heavy"}

		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/hydraulic/hydraulic_heavy"}
	}
)
(define "ferdinand_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/ferdinand/start"}
		{link_sound "engine_stop"		"vehicle/engine/ferdinand/stop"}
		{link_sound "engine_idle"		"vehicle/engine/ferdinand/idle"}
		{link_sound "engine_full"		"vehicle/engine/ferdinand/full"}
		{link_sound "exhaust"			"vehicle/engine/ferdinand/exhaust"}
		{link_sound "move"			"vehicle/tracks/ferdinand/"}
		{link_sound "rotate_turret"		"vehicle/turret/gun/gun_horizontal"}

		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
	}
)
(define "pz6b_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/pz6b/start"}
		{link_sound "engine_stop"		"vehicle/engine/pz6b/stop"}
		{link_sound "engine_idle"		"vehicle/engine/pz6b/idle"}
		{link_sound "engine_full"		"vehicle/engine/pz6b/full"}
		{link_sound "exhaust"			"vehicle/engine/pz6b/exhaust"}
		{link_sound "move"			"vehicle/tracks/pz6b/"}
		{link_sound "rotate_turret"		"vehicle/turret/hydraulic/hydraulic_heavy"}

		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/hydraulic/hydraulic_heavy"}
	}
)

;/*=========== German Vehicles End ===========*/

;/*=========== Soviet Vehicles Begin ===========*/

(define "s60_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/s60/start"}
		{link_sound "engine_stop"		"vehicle/engine/s60/stop"}
		{link_sound "engine_idle"		"vehicle/engine/s60/idle"}
		{link_sound "engine_full"		"vehicle/engine/s60/full"}
		{link_sound "exhaust"			"vehicle/engine/s60/exhaust"}
		{link_sound "move"			"vehicle/tracks/s60/"}
	}
)
(define "universal2_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/universal2/start"}
		{link_sound "engine_stop"		"vehicle/engine/universal2/stop"}
		{link_sound "engine_idle"		"vehicle/engine/universal2/idle"}
		{link_sound "engine_full"		"vehicle/engine/universal2/full"}
		{link_sound "exhaust"			"vehicle/engine/s60/exhaust"}
		{link_sound "move"			"vehicle/wheels/truck/"}
	}
)

(define "zis5_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/zis5/start"}
		{link_sound "engine_stop"		"vehicle/engine/zis5/stop"}
		{link_sound "engine_idle"		"vehicle/engine/zis5/idle"}
		{link_sound "engine_full"		"vehicle/engine/zis5/full"}
		{link_sound "exhaust"			"vehicle/engine/zis5/exhaust"}
		{link_sound "move"			"vehicle/wheels/truck"}
	}
)

(define "studebaker_sound" ;// Temp until it gets it's own sound
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/zis5/start"}
		{link_sound "engine_stop"		"vehicle/engine/zis5/stop"}
		{link_sound "engine_idle"		"vehicle/engine/zis5/idle"}
		{link_sound "engine_full"		"vehicle/engine/zis5/full"}
		{link_sound "exhaust"			"vehicle/engine/zis5/exhaust"}
		{link_sound "move"			"vehicle/wheels/truck"}
	}
)

(define "gaz_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/gaz/start"}
		{link_sound "engine_stop"		"vehicle/engine/gaz/stop"}
		{link_sound "engine_idle"		"vehicle/engine/gaz/idle"}
		{link_sound "engine_full"		"vehicle/engine/gaz/full"}
		{link_sound "exhaust"			"vehicle/engine/gaz/exhaust"}
		{link_sound "move"			"vehicle/wheels/car/"}
	}
)

(define "ba_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "engine_start"		"vehicle/engine/ba/start"}
		{link_sound "engine_stop"		"vehicle/engine/ba/stop"}
		{link_sound "engine_idle"		"vehicle/engine/ba/idle"}
		{link_sound "engine_full"		"vehicle/engine/ba/full"}
		{link_sound "exhaust"			"vehicle/engine/ba/exhaust"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
		{link_sound "move"			"vehicle/wheels/armored_car"}
		{link_sound "brake"			"vehicle/wheels/brake"}

		{link_sound "wheel_ground"  		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_grass" 		"vehicle/wheels/overlay/wheel_overlay_ground"}
		{link_sound "wheel_water" 		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_puddle" 		"vehicle/wheels/overlay/wheel_overlay_water"}
		{link_sound "wheel_mud" 		"vehicle/wheels/overlay/wheel_overlay_mud_snow"}
		{link_sound "wheel_snow" 		"vehicle/wheels/overlay/wheel_overlay_mud_snow"}
		{link_sound "wheel_road" 		"vehicle/wheels/overlay/wheel_overlay_road"}
		{link_sound "wheel_rock" 		"vehicle/wheels/overlay/wheel_overlay_rock"}
		{link_sound "wheel_wood" 		"vehicle/wheels/overlay/wheel_overlay_wood"}
	}
)
(define "t26_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "engine_start"		"vehicle/engine/t26/start"}
		{link_sound "engine_stop"		"vehicle/engine/t26/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t26/idle"}
		{link_sound "engine_full"		"vehicle/engine/t26/full"}
		{link_sound "exhaust"			"vehicle/engine/t26/exhaust"}
		{link_sound "move"				"vehicle/tracks/t26/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
	}
)
(define "t27_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "engine_start"		"vehicle/engine/t27/start"}
		{link_sound "engine_stop"		"vehicle/engine/t27/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t27/idle"}
		{link_sound "engine_full"		"vehicle/engine/t27/full"}
		{link_sound "exhaust"			"vehicle/engine/t27/exhaust"}
		{link_sound "move"				"vehicle/tracks/t27/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
	}
)
(define "t28_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/t28/start"}
		{link_sound "engine_stop"		"vehicle/engine/t28/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t28/idle"}
		{link_sound "engine_full"		"vehicle/engine/t28/full"}
		{link_sound "exhaust"			"vehicle/engine/t28/exhaust"}
		{link_sound "move"				"vehicle/tracks/t28/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
	}
)
(define "bt_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "engine_start"		"vehicle/engine/bt/start"}
		{link_sound "engine_stop"		"vehicle/engine/bt/stop"}
		{link_sound "engine_idle"		"vehicle/engine/bt/idle"}
		{link_sound "engine_full"		"vehicle/engine/bt/full"}
		{link_sound "exhaust"			"vehicle/engine/bt/exhaust"}
		{link_sound "move"				"vehicle/tracks/bt/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
	}
)
(define "t70_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/light/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/light/"}
		{link_sound "engine_start"		"vehicle/engine/t70/start"}
		{link_sound "engine_stop"		"vehicle/engine/t70/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t70/idle"}
		{link_sound "engine_full"		"vehicle/engine/t70/full"}
		{link_sound "exhaust"			"vehicle/engine/t70/exhaust"}
		{link_sound "move"				"vehicle/tracks/t70/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
	}
)
(define "t34_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/t34/start"}
		{link_sound "engine_stop"		"vehicle/engine/t34/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t34/idle"}
		{link_sound "engine_full"		"vehicle/engine/t34/full"}
		{link_sound "exhaust"			"vehicle/engine/t34/exhaust"}
		{link_sound "move"				"vehicle/tracks/t34/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_light"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_light"}
	}
)
(define "kv_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/kv/start"}
		{link_sound "engine_stop"		"vehicle/engine/kv/stop"}
		{link_sound "engine_idle"		"vehicle/engine/kv/idle"}
		{link_sound "engine_full"		"vehicle/engine/kv/full"}
		{link_sound "exhaust"			"vehicle/engine/kv/exhaust"}
		{link_sound "move"				"vehicle/tracks/kv/"}
		{link_sound "rotate_turret"		"vehicle/turret/handcrank/handcrank_heavy"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/handcrank/handcrank_heavy"}
	}
)
(define "is_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_fail"		"vehicle/engine/damage/EXT/heavy/"}
		{link_sound "engine_fail_INT"		"vehicle/engine/damage/INT/heavy/"}
		{link_sound "engine_start"		"vehicle/engine/is/start"}
		{link_sound "engine_stop"		"vehicle/engine/is/stop"}
		{link_sound "engine_idle"		"vehicle/engine/is/idle"}
		{link_sound "engine_full"		"vehicle/engine/is/full"}
		{link_sound "exhaust"			"vehicle/engine/is/exhaust"}
		{link_sound "move"				"vehicle/tracks/is/"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_heavy"}
		{link_sound "rotate_turret_INT"		"vehicle/turret/INT/electric/electric_heavy"}
	}
)

;/*=========== Soviet Vehicles End ===========*/

;/*=========== Lend-Lease Vehicles Begin ===========*/


(define "studebaker_sound" ;// Temp until it gets it's own sound
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/zis5/start"}
		{link_sound "engine_stop"		"vehicle/engine/zis5/stop"}
		{link_sound "engine_idle"		"vehicle/engine/zis5/idle"}
		{link_sound "engine_full"		"vehicle/engine/zis5/full"}
		{link_sound "exhaust"			"vehicle/engine/zis5/exhaust"}
		{link_sound "move"			"vehicle/wheels/truck"}
	}
)

(define "universal_carrier_sound" ;// Temp until it gets it's own sound
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t27/start"}
		{link_sound "engine_stop"		"vehicle/engine/t27/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t27/idle"}
		{link_sound "engine_full"		"vehicle/engine/t27/full"}
		{link_sound "exhaust"			"vehicle/engine/t27/exhaust"}
		{link_sound "move"			"vehicle/tracks/t27/"}
	}
)

(define "valentine_sound"
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/valentine/start"}
		{link_sound "engine_stop"		"vehicle/engine/valentine/stop"}
		{link_sound "engine_idle"		"vehicle/engine/valentine/idle"}
		{link_sound "engine_full"		"vehicle/engine/valentine/full"}
		{link_sound "exhaust"			"vehicle/engine/valentine/exhaust"}
		{link_sound "move"			"vehicle/tracks/valentine/"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_light"}
	}
)
(define "churchill_sound"	 ;// Temp until it gets it's own sound
	{on "add_movement_sound" overload
		{link_sound "engine_start"		"vehicle/engine/t28/start"}
		{link_sound "engine_stop"		"vehicle/engine/t28/stop"}
		{link_sound "engine_idle"		"vehicle/engine/t28/idle"}
		{link_sound "engine_full"		"vehicle/engine/t28/full"}
		{link_sound "exhaust"			"vehicle/engine/t28/exhaust"}
		{link_sound "move"			"vehicle/tracks/t28/"}
		{link_sound "rotate_turret"		"vehicle/turret/electric/electric_heavy"}
	}
)


;/*=========== Lend-Lease Vehicles End ===========*/

;/*=========== Generic Cannon Groups Begin ===========*/

(define "cannon_skis"
	{on "add_movement_sound" overload ;// split add movements into separate define and nest this one into it. separate so different turret/gun rotate sounds can be added.
		{link_sound "rotate_turret"		"vehicle/turret/cannon/small"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/small"}
	}

	{on spawn
		{link_sound "wheel_ground"		"vehicle/cannon_roll/overlays/cannon_ski_overlay_rock"}
		{link_sound "wheel_sand"		"vehicle/cannon_roll/overlays/cannon_ski_overlay_snow"}
		{link_sound "wheel_grass"		"vehicle/cannon_roll/overlays/cannon_ski_overlay_rock"}
		{link_sound "wheel_water"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_puddle"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_mud"			"vehicle/cannon_roll/overlays/cannon_ski_overlay_rock"}
		{link_sound "wheel_snow"		"vehicle/cannon_roll/overlays/cannon_ski_overlay_snow"}
		{link_sound "wheel_road"		"vehicle/cannon_roll/overlays/cannon_ski_overlay_rock"}
		{link_sound "wheel_rock"		"vehicle/cannon_roll/overlays/cannon_ski_overlay_rock"}
		{link_sound "wheel_wood"		"vehicle/cannon_roll/overlays/cannon_ski_overlay_rock"}
	}
)

(define "cannon_small"
	{on "add_movement_sound" overload ;// split add movements into separate define and nest this one into it. separate so different turret/gun rotate sounds can be added.
		{link_sound "rotate_turret"		"vehicle/turret/cannon/small"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/small"}
	}

	{on spawn
		{link_sound "wheel_ground"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_grass"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_water"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_puddle"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_mud"			"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_snow"		"vehicle/cannon_roll/overlays/cannon_overlay_snow"}
		{link_sound "wheel_road"		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_rock"		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_wood"		"vehicle/cannon_roll/overlays/cannon_overlay_wood"}
	}
)

(define "cannon_big"
	{on "add_movement_sound" overload ;// split add movements into separate define and nest this one into it. separate so different turret/gun rotate sounds can be added.
		{link_sound "rotate_turret"		"vehicle/turret/cannon/big"}
		{link_sound "rotate_gun"		"vehicle/turret/cannon/big"}
	}

	{on spawn
		{link_sound "wheel_ground"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_sand"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_grass"		"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_water"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_puddle"		"vehicle/cannon_roll/overlays/cannon_overlay_water"}
		{link_sound "wheel_mud"			"vehicle/cannon_roll/overlays/cannon_overlay_ground"}
		{link_sound "wheel_snow"		"vehicle/cannon_roll/overlays/cannon_overlay_snow"}
		{link_sound "wheel_road"		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_rock"		"vehicle/cannon_roll/overlays/cannon_overlay_rock_road"}
		{link_sound "wheel_wood"		"vehicle/cannon_roll/overlays/cannon_overlay_wood"}
	}
)
;/*=========== Generic Cannon Groups End ===========*/
