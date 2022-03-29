
;/*================ Triggered by Hardcode Events Begin ================*/


{talk "cannon_explosion"			;// on signal "explosion" ?
	("cannon_phrases" args alert)
	{freq 1}
}

{talk "cannon_kill_enemy"			;// on enemy killed (added to kill counter)
	("cannon_phrases" args enemy_is_destroyed)
	{freq 1}
}

{talk "cannon_i am rambo"			;// replaces kill_enemy sound after 3 to 6 units killed one time. Subsequent kills return to "kill_enemy"
	("cannon_phrases" args i_am_rambo)
	{freq 1}
}

{talk "cannon_attack"				;// on executing an attack order
	("cannon_phrases" args attack)
	{freq 1}
}

{talk "cannon_executing_order"		;// on executing move order
	("cannon_phrases" args executing_an_order)
	{freq 1}
}

{talk "cannon_selection"			;// on selecting an owned unit
	("cannon_phrases" args selection_of_units)
	{freq 1}
}

{talk "cannon_bullet missed"		;// if shot bullet missed its target, called for shooting unit
	("cannon_phrases" args missed_shot)
	{freq 0.2}
}

{talk "cannon_ill_take_it"			;// item was automatically distributed to squad member (if not ammo or grenade)
	("cannon_phrases" args ill_take_item)
	{freq 1}
}

{talk "cannon_ill_take_ammo"		;// ammo was distributed to squad member
	("cannon_phrases" args ill_take_item)
	{freq 1}
}

{talk "cannon_cannot do this"		;// general reaction if unit cannot follow order: on trying to perform inventory operations while swimming, on trying to board vehicle with enemy or neutral units in one of its places (probably not used anymore)
	("cannon_phrases" args impossibility_to_execute_an_order)
	{freq 1}
}

{talk "cannon_too heavy item(s)"	;// on trying to receive item that would make carried stuff exceed max mass of 110kg
	("cannon_phrases" args item_too_heavy)
	{freq 1}
}

{talk "cannon_inventory full"		;// on trying to receive item that does not fit the inventory
	("cannon_phrases" args inventory_full)
	{freq 1}
}

{talk "cannon_leave"				;// on passenger leave the "cannon" speaks
	("cannon_phrases" args leave)
	{freq 1}
}

;/*================ Triggered by Hardcode Events End ================*/


;/*================ Triggered by Interaction Scripts or Conditions Begin ================*/

{talk "cannon_advantage"		;// (condition) - friendly units outnumber detected enemies
	("cannon_phrases" args advantage)
	{freq 1}
}

{talk "cannon_idle"				;// (condition) - called when not in combat and does not detect any enemies
	("cannon_phrases" args idle)
	{freq 1}
}

{talk "cannon_in_battle"		;// (condition) - called when unit is in "battle" brain state
	("cannon_phrases" args in_battle)
	{freq 1}
}

{talk "cannon_broken_gun"		;// (interaction script) - called when gun component breaks
	("cannon_phrases" args broken_gun)
	{freq 1}
}

{talk "cannon_grenade"			;// (interaction script) - grenade contacts cannon, crew emits
	("cannon_phrases" args grenade)
	{freq 1}
}

{talk "cannon_shoot"			;// (interaction script) - cannon shoots gun
	("cannon_phrases" args shoot)
	{freq 1}
}

{talk "cannon_reload"			;// (interaction script) - called seconds after reload begins
	("cannon_phrases" args reload)
	{freq 1}
}

{talk "cannon_reloaded"			;// (interaction script) - called when reload is complete
	("cannon_phrases" args reloaded)
	{freq 1}
}

;/*================ Triggered by Interaction Scripts or Conditions End ================*/