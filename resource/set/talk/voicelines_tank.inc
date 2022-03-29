
;/*================ Triggered by Hardcode Events Begin ================*/

{talk "tank_kill_enemy"				;// on enemy killed (added to kill counter)
	("tank_phrases" args enemy_is_destroyed)
	{freq 1}
}

{talk "tank_i am rambo"				;// replaces kill_enemy sound after 3 to 6 units killed one time. Subsequent kills return to "kill_enemy"
	("tank_phrases" args i_am_rambo)
	{freq 1}
}

{talk "tank_attack"					;// on executing an attack order
	("tank_phrases" args attack)
	{freq 1}
}

{talk "tank_executing_order"		;// on executing move order
	("tank_phrases" args executing_an_order)
	{freq 1}
}

{talk "tank_selection"				;// on selecting an owned unit
	("tank_phrases" args selection_of_units)
	{freq 1}
}

{talk "tank_bullet missed"			;// if shot bullet missed its target, called for shooting unit
	("tank_phrases" args missed_shot)
	{freq 0.2}
}

{talk "tank_ill_take_it"			;// item was automatically distributed to squad member (if not ammo or grenade)
	("tank_phrases" args ill_take_item)
	{freq 1}
}

{talk "tank_ill_take_ammo"			;// ammo was distributed to squad member
	("tank_phrases" args ill_take_item)
	{freq 1}
}

{talk "tank_cannot do this"			;// general reaction if unit cannot follow order: on trying to perform inventory operations while swimming, on trying to board vehicle with enemy or neutral units in one of its places (probably not used anymore)
	("tank_phrases" args impossibility_to_execute_an_order)
	{freq 1}
}

{talk "tank_too heavy item(s)"		;// on trying to receive item that would make carried stuff exceed max mass of 110kg
	("tank_phrases" args item_too_heavy)
	{freq 1}
}

{talk "tank_inventory full"			;// on trying to receive item that does not fit the inventory
	("tank_phrases" args inventory_full)
	{freq 1}
}


;/*================ Triggered by Hardcode Events End ================*/


;/*================ Triggered by Interaction Scripts or Conditions Begin ================*/


{talk "tank_alert_airborne"		;// (condition) - unit sees vehicle with "airborne" prop
	("tank_phrases" args alert_airborne)
	{freq 0.2}
}

{talk "tank_alert_tank"			;// (condition) - unit sees vehicle with "tank" prop
	("tank_phrases" args alert_tank)
	{freq 1}
}

{talk "tank_alert_at_gun"		;// (condition) - unit sees vehicle with "at_gun" prop
	("tank_phrases" args alert_at_gun)
	{freq 1}
}

{talk "tank_idle"				;// (condition) - called when not in combat and does not detect any enemies
	("tank_phrases" args idle)
	{freq 1}
}

{talk "tank_in_battle"			;// (condition) - called when unit is in "battle" brain state
	("tank_phrases" args in_battle)
	{freq 0.8}
}

{talk "tank_advantage"			;// (condition) - friendly units outnumber detected enemies
	("tank_phrases" args advantage)
	{freq 1}
}

{talk "tank_retreat"			;// (condition) - called when detected enemies greatly outnumber friendly unit
	("tank_phrases" args retreat)
	{freq 1}
}

{talk "tank_crew_die"			;// (interaction script) - called when crew are killed via script (is not called when visible crew are killed with direct damage)
	("tank_phrases" args crew_die)
	{freq 1}
}

{talk "tank_broken_gun"			;// (interaction script) - called when gun component breaks
	("tank_phrases" args broken_gun)
	{freq 1}
}

{talk "tank_broken_turret"		;// (interaction script) - called when turret component breaks
	("tank_phrases" args broken_turret)
	{freq 1}
}

{talk "tank_broken_engine"		;// (interaction script) - called when engine component breaks
	("tank_phrases" args broken_engine)
	{freq 1}
}

{talk "tank_broken_track"		;// (interaction script) - called when track component breaks
	("tank_phrases" args broken_track)
	{freq 1}
}

{talk "tank_burning"			;// (interaction script) - called when tank is on fire
	("tank_phrases" args burning)
	{freq 1}
}

{talk "tank_shoot"				;// (interaction script) - cannon shoots gun
	("tank_phrases" args shoot)
	{freq 1}
}

{talk "tank_reload"				;// (interaction script) - called seconds after reload begins
	("tank_phrases" args reload)
	{freq 1}
}

{talk "tank_reloaded"			;// (interaction script) - called when reload is complete
	("tank_phrases" args reloaded)
	{freq 1}
}

;/*================ Triggered by Interaction Scripts or Conditions End ================*/