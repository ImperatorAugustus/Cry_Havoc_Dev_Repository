;SDL
{"air"
(include "\set\interaction_terrain\effects\effects-defines.inc")
	{on detonate
		{if stuff "grenade fire"	; ...........................................................................	Molotov Grenades
			;{spawn "ex_molot_ground"}
;---------------------------------------------------------------------------------------------------------------------		GRENADES & EXPLOSIVES
		else stuff "grenade size1"	; ...........................................................................	Fillings from 0.0 to 0.10 Kg - f.e. F 1, RGD 33
			("explosion_minimum")
			{spawn "ex_air_minimum"}
		else stuff "grenade size2"	; ...........................................................................	Fillings from 0.10 to 0.60 Kg - f.e. M 24 Stielhandgranate, M 67, Dynamite x3 
			("explosion_grenade")
			{spawn "ex_air_small"}
		else stuff "grenade size3"	; ...........................................................................	Fillings from 0.60 to 1.50 Kg - f.e. M 24 Geballte Ladung, RPG 40, RPG 43, Dynamite x7
			("explosion_small")
			{spawn "shockwave_sphere"}
			{spawn "ex_air_small"}
		else stuff "grenade size4"	; ...........................................................................	Fillings from 3.00 to 7.00 Kg - f.e. 3kg Geballteladung, TMi 35/44, M 37 Satchel, TMD-B and TMD-44
			("explosion_medium")
			{spawn "ex_air_medium"}
;------------------------------------------------------------------------------------------------------------------------------------	MINES
		else stuff "mine antipersonnel"		; ...........................................................................	Anti-Personnel Mines
			("explosion_grenade")
			{spawn "shockwave_sphere"}
			{spawn "ex_air_small"}
;------------------------------------------------------------------------------------------------------------------------------------	OTHERS
		}
	}
}