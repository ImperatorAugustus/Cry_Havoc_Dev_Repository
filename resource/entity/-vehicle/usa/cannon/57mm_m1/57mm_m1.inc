
	(include "/properties/cannon.ext")
	{extension "57mm_m1.mdl"}
	(include "/properties/selection/cannon.inc" scale(0.7))
	{props "57mm_m1" "wheeled" "vision_lev02_can" "muzzle_50mm_57mm" "cannon_sandbag_small" "trailer" "trailer_medium" "detect_atgun_small" "c_at_med"}

	("wheel" args "wheelright")
	("wheel" args "wheelleft")

	("gun" repair(30) thickness(30))
	("shield_group" args "shield1" 8 "shield")
	("shield_group" args "shield2" 8 "shield")
	("shield_group" args "shield3" 8 "shield")
	("shield_group" args "shield21" 8 "shield2")
	("shield_group" args "shield22" 8 "shield2")
	("shield_group" args "shield23" 8 "shield2")
	("shield" args "shield_lower" 8)

	("armor_medium_cannon")
	("crew_wheeled_cannon_4")

	{volume "shield1" {able {holed}}}
	{volume "body2" {able {holed}}}

	{boarder
		{anm "gunner"
			{forward {end "cannon_small_gunner" 10}}
		}
		{anm "charger"
			{forward {end "cannon_small_charger" 10}}
		}
		{anm "charger2"
			{forward {end "cannon_small_charger2" 10}}
		}
		{anm "commander"
			{forward {end "cannon_small_commander" 10}}
		}
		{anm "driver1"	;// gunner
			{forward {end "cannon_pak40_pusher_left" 10}}
		}
		{anm "driver2"	;// charger
			{forward {end "cannon_pak40_pusher_right" 10}}
		}
		{anm "driver3"	;// charger2
			{forward {end "mortar_driver_l" 10}}
		}
		{anm "driver4"	;// commander
			{forward {end "mgun_browning_driver_r" 10}}
		}
		{anm "seat1"	;// gunner
			{forward {end "pose_seat_cannon_left" 10}}
		}
		{anm "seat2"	;// charger
			{forward {end "pose_seat_cannon_right" 10}}
		}
		{anm "seat3"	;// charger2
			{forward {end "pose_seat_cannon_right" 10}}
		}
		{anm "seat4"	;// commander
			{forward {end "pose_seat_cannon_left" 10}}
		}
	}

	{extender "cannon"
		{animation
			{switch "close"}
			;// "gunner" "charger" "charger2" "commander"
			{move "cannon_pak40_pusher_left" "cannon_pak40_pusher_right" "mortar_driver_l" "mgun_browning_driver_r" }
			{aim "cannon_small_gunner_aim" "cannon_small_charger_aim" "cannon_small_charger2_aim" "cannon_small_commander_aim"}
			{fire "cannon_small_gunner_fire" "cannon_small_charger_fire" "cannon_small_charger2_fire" "cannon_small_commander_fire"}
			{reload "cannon_small_gunner_reload" "cannon_small_charger_reload" "cannon_small_charger2_reload" "cannon_small_commander_reload"}
		}
		{move {workers "driver1" "driver2" "driver3" "driver4" minWorkers 2} {obstacle "close"}}			;// move state: cannon being pushed and which positions play animations
		{attack {workers "gunner" "charger" "charger2" "commander"} {obstacle "open"}}		;// fire/attack state: cannon aim, fire, and reload events
		{trailing {workers "seat1" "seat2" "seat3" "seat4"}}								;// trailing state: cannon is being towed {obstacle} not needed. Uses "close"
	}

	{mass 1215}
	{Chassis "track"
		("car_trace" fx("tracewheel06") step(0.07) wheell("wlf") wheelr("wrf") bonel("FXtraceL1") boner("FXtraceR1"))
		("mobility_cannon"
			speed(6.6) ;---------------------------------Max speed.
			weight(1215) ;--------------------------------Weight in Kilograms.
		)
	}

	{bone "basis"
		{speed2 6.5}
	}
	{bone "gun_rot"
		{limits -5 15}
		{speed2 10}
	}
	{bone "turret"
		{limits -45 45}
		{speed2 18}
	}
