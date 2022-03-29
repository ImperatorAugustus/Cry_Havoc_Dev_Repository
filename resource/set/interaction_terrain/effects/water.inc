;SDL

(define "water_bullets"             ; ********************************************************************************* PROJECTILES THAT DO NOT EXPLODE
	{if stuff "bullet_fx size1"											; 7.62x25mm - 11.43x23mm
		{spawn "ex_bul_sm_w"}
	else stuff "bullet_fx size2"											; 7.62x33mm - 7.92x94mm
		{spawn "ex_bul_sm_w"}
	else stuff "bullet_fx size3"											; 12.7x99mm - 14.5x114mm
		{spawn "ex_bul_big_w"}
	else stuff "auto"												; 20-40mm Autocannon shells
		{spawn "ex_bul_big_w"}
	else stuff "shell size1"											; 37-74mm cannon AP shells
		{spawn "ex_size1_water"}
		{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
	else stuff "shell size2"											; 75-104mm cannon AP shells
		{spawn "ex_size2_water"}
		{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
	else stuff "shell size3"											; 105-149mm cannon AP shells
		{spawn "ex_size3_water"}
		{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
	else stuff "shell size4"											; 150-169mm cannon AP shells
		{spawn "ex_size4_water"}
		{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
	else stuff "shell size5"											; 105-149mm cannon AP shells
		{spawn "ex_size4_water"}
		{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
	else stuff "shell size6"											; 150-169mm cannon AP shells
		{spawn "ex_size4_water"}
		{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}	
	else stuff "flare"												; Special Flare ammo for mission scripts
		{spawn "ex_bul_sm_w"}	
	else stuff "glass ic"												; Ampulomet glass ball
		{spawn "ex_bul_sm_w"}
	}
)

(define "water_detonate"             ; ********************************************************************************* PROJECTILES AND DEVICES THAT EXPLODE IN, OR ON CONTACT WITH WATER 
		{if stuff "auto he" 			; ...........................................................................	20-40mm Autocannon HE shells
			{spawn "ex_bul_big_w"}							
;---------------------------------------------------------------------------------------------------------------------	GRENADES & EXPLOSIVES
		else stuff "grenade size1"		; ...........................................................................	Fillings from 0.0 to 0.10 Kg - f.e. F 1, RGD 33
			{spawn "ex_size1_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "grenade size2"		; ...........................................................................	Fillings from 0.10 to 0.60 Kg - f.e. M 24 Stielhandgranate, M 67, Dynamite x3 
			{spawn "ex_size1_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "grenade size3"		; ...........................................................................	Fillings from 0.60 to 1.50 Kg - f.e. M 24 Geballte Ladung, RPG 40, RPG 43, Dynamite x7
			{spawn "ex_size2_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "grenade size4"		; ...........................................................................	Fillings from 3.00 to 7.00 Kg - f.e. 3kg Geballteladung, TMi 35/44, M 37 Satchel, TMD-B and TMD-44
			{spawn "ex_size3_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
;---------------------------------------------------------------------------------------------------------------------	MORTARS
		else stuff "mortar size1 he"		; ...........................................................................	50-60mm Mortar shells
			{spawn "ex_size1_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "mortar size2 he"		; ...........................................................................	82mm Mortar shells
			{spawn "ex_size2_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "big mortar ic"		; ...........................................................................	107-120mm Mortar incendiary	
			{spawn "ex_size2_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "mortar size3 he"		; ...........................................................................	120mm Mortar shells
			{spawn "ex_size3_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
;---------------------------------------------------------------------------------------------------------------------	HEAT SHELLS
		else stuff "heat_shell size1"		; ...........................................................................	37-74mm
			{spawn "ex_size1_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "heat_shell size2"		; ...........................................................................	75-104mm
			{spawn "ex_size2_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "heat_shell size3"		; ...........................................................................	105-149mm
			{spawn "ex_size3_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "heat_shell size4"		; ...........................................................................	105-149mm
			{spawn "ex_size4_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
;---------------------------------------------------------------------------------------------------------------------	HE SHELLS
		else stuff "shell size1 he"		; ...........................................................................	Fillings from 0.0 to 0.20 Kg
			{spawn "ex_size1_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "shell size2 he"		; ...........................................................................	Fillings from 0.20 to 1.00 Kg
			{spawn "ex_size2_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "shell size3 he"		; ...........................................................................	Fillings from 1.00 to 3.50 Kg
			{spawn "ex_size3_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "shell size4 he"		; ...........................................................................	Fillings from 3.50 to 7.00 Kg
			{spawn "ex_size3_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "shell size5"		; ...........................................................................	Fillings from 7.00 to 12.00 Kg
			{spawn "ex_size4_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "shell size6"		; ...........................................................................	Fillings 12.00+ Kg
			{spawn "ex_size4_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
;---------------------------------------------------------------------------------------------------------------------	AIRCRAFT BOMBS
		else stuff "bomb size1"			; ...........................................................................	50-60kg bombs / explosives
			{spawn "ex_size3_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "bomb size2"			; ...........................................................................	 100-200kg bombs / explosives
			{spawn "ex_size4_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "bomb size3"			; ...........................................................................	250kg+ bomb
			{spawn "ex_size4_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
;---------------------------------------------------------------------------------------------------------------------	MINES
		else stuff "mine antipersonnel"		; ...........................................................................	Anti-Personnel Mines
			{spawn "ex_size1_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
		else stuff "mine antitank"		; ...........................................................................	Anti-Tank Mines
			{spawn "ex_size2_water"}
			{start_sound "detonation/explosion_mechanical/terrain/Water/" use_position}
	}
)

(define "shallow_water_detonate"
		{if stuff "grenade fire"		; ...........................................................................	Molotov Grenades
			{spawn "ex_molot_ground"}
;----------------------------------------------------------------------------------------------------------------------------	BULLETS
		else stuff "bullet_fx size1"		; ...........................................................................	7.62x25mm - 11.43x23mm
			{spawn "ex_bul_sm_mud"}
		else stuff "bullet_fx size2"		; ...........................................................................	7.62x33mm - 7.92x94mm
			("sonic_crack")
			{spawn "ex_bul_sm_mud"}
		else stuff "bullet_fx size3"		; ...........................................................................	12.7x99mm - 14.5x114mm
			("sonic_crack_medium")
			{spawn "ex_apcr_autocannon_mud"}
;----------------------------------------------------------------------------------------------------------------------------	20MM TO 40MM AA
		else stuff "auto ap"			; ...........................................................................	AP
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_size1_mud"}
		else stuff "auto apbc"			; ...........................................................................	APBC										
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_size1_mud"}
		else stuff "auto aphe"			; ...........................................................................	APHE									
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_size1_mud"}
		else stuff "auto apcr"			; ...........................................................................	APCR								
			("sonic_crack_medium")
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_apcr_autocannon_mud"}
		else stuff "auto he"			; ...........................................................................	HE
			("explosion_he_auto")
			{spawn "ex_he_autocannon_mud"}
;----------------------------------------------------------------------------------------------------------------------------	RIFLE GRENADES
		else stuff "rifle_grenade"		; ...........................................................................	HE rifle Grenades
			("explosion_minimum")
			{spawn "ex_he_size1_mud"}
		else stuff "rifle_grenade_at"		; ...........................................................................	HEAT rifle Grenades
			("explosion_minimum")
			{spawn "ex_he_size1_mud"}
;---------------------------------------------------------------------------------------------------------------------		GRENADES & EXPLOSIVES
		else stuff "grenade size1"		; ...........................................................................	Fillings from 0.0 to 0.10 Kg - f.e. F 1, RGD 33
			("explosion_minimum")
			{spawn "ex_he_size1_mud"}
		else stuff "grenade size2"		; ...........................................................................	Fillings from 0.10 to 0.60 Kg - f.e. M 24 Stielhandgranate, M 67, Dynamite x3 
			("explosion_grenade")
			{spawn "ex_he_size1_mud"}
		else stuff "grenade size3"		; ...........................................................................	Fillings from 0.60 to 1.50 Kg - f.e. M 24 Geballte Ladung, RPG 40, RPG 43, Dynamite x7
			("explosion_small")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size2_mud"}
		else stuff "grenade size4"		; ...........................................................................	Fillings from 3.00 to 7.00 Kg - f.e. 3kg Geballteladung, TMi 35/44, M 37 Satchel, TMD-B and TMD-44
			("explosion_medium")
			{spawn "shockwave_sphere"}
			{spawn "ex_at_mine"}
;------------------------------------------------------------------------------------------------------------------------------------	MORTARS
		else stuff "mortar size1 he"		; ...........................................................................	50-70mm Mortar shells
			("explosion_grenade")
			{spawn "ex_he_size1_mud"}
			{spawn "grenade_shellhole" terrain_texmod}
		else stuff "mortar size2 he"		; ...........................................................................	80mm Mortar shells
			("explosion_small")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size2_mud"}
		else stuff "big mortar ic"		; ...........................................................................	107-120mm Mortar incendiary	
			{start_sound "detonation/explosion_medium/mid/" use_position}
			{start_sound "detonation/explosion_medium/far/" use_position}
			{start_sound "fire/bush/" use_position}
			{spawn "ex_ic_120_ground"}
			{spawn "burn_piece" dir_velocity}
			{fire radius 4 time 20 heating 0.25}
		else stuff "mortar size3 he"		; ...........................................................................	107-120mm Mortar shells
			("explosion_large")
			{spawn "shockwave_sphere"}
			{spawn "ex_at_mine"}
;------------------------------------------------------------------------------------------------------------------------------------	HEAT SHELLS
		else stuff "heat_shell size1"		; ...........................................................................	37-74mm
			("explosion_HEAT")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size1_mud"}
		else stuff "heat_shell size2l"		; ...........................................................................	75-104mm
			("explosion_HEAT")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size2_mud"}
		else stuff "heat_shell size3"		; ...........................................................................	105-149mm
			("explosion_HEAT_large")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size3_mud"}
		else stuff "heat_shell size4"		; ...........................................................................	150-169mm
			("explosion_HEAT_large")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size3_mud"}
;------------------------------------------------------------------------------------------------------------------------------------	AP w/Filler SHELLS
		else stuff "shell size1 hasfiller"	; ...........................................................................	37-74mm
			{spawn "ex_ap_size1_mud"}
		else stuff "shell size2 hasfiller"	; ...........................................................................	75-104mm
			("explosion_ap")
			{spawn "ex_ap_size2_mud"}
		else stuff "shell size3 hasfiller"	; ...........................................................................	105-149mm
			("explosion_ap")
			{spawn "ex_ap_size3_mud"}
		else stuff "shell size4 hasfiller"	; ...........................................................................	150-169mm
			("explosion_ap")
			{start_sound "detonation/explosion_mechanical/trickle/short/" use_position}
			{spawn "ex_ap_size4_mud"}
;------------------------------------------------------------------------------------------------------------------------------------	APCR Shells
		else stuff "shell size1 apcr"		; ...........................................................................	37-74mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_size1_mud"}
		else stuff "shell size2 apcr"		; ...........................................................................	75-104mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{spawn "ex_ap_size2_mud"}
		else stuff "shell size3 apcr"		; ...........................................................................	105-149mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{start_sound "detonation/explosion_mechanical/trickle/short/" use_position}
			{spawn "ex_ap_size3_mud"}
		else stuff "shell size4 apcr"		; ...........................................................................	150-169mm
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
			{start_sound "detonation/explosion_mechanical/trickle/short/" use_position}
			{spawn "ex_ap_size4_mud"}
;------------------------------------------------------------------------------------------------------------------------------------	HE SHELLS
		else stuff "shell size1 he"		; ...........................................................................	Fillings from 0.0 to 0.20 Kg
			("explosion_minimum")
			{spawn "ex_he_size1_mud"}
		else stuff "shell size2 he"		; ...........................................................................	Fillings from 0.20 to 1.00 Kg
			("explosion_small")
			{spawn "ex_he_size2_mud"}
		else stuff "shell size3 he"		; ...........................................................................	Fillings from 1.00 to 3.50 Kg
			("explosion_medium")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size3_mud"}
		else stuff "shell size4 he"		; ...........................................................................	Fillings from 3.50 to 7.00 Kg
			("explosion_large")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size4"}
		else stuff "shell size5"		; ...........................................................................	Fillings from 7.00 to 12.00 Kg
			("explosion_massive")
			{spawn "ex_he_size5"}
		else stuff "shell size6"		; ...........................................................................	Fillings 12.00+ Kg
			("explosion_massive")
			{spawn "shockwave_sphere"}
			{spawn "ex_he_size6"}
;------------------------------------------------------------------------------------------------------------------------------------	AIRCRAFT BOMBS
		else stuff "bomb size1"			; ...........................................................................	50-60kg bombs / explosives
			("explosion_large")
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_50kg"}
		else stuff "bomb size2"			; ...........................................................................	100-200kg bombs / explosives
			("explosion_massive")
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_100kg"}
		else stuff "bomb size3"			; ...........................................................................	250kg+ bomb
			("explosion_massive")
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_250kg"}
;------------------------------------------------------------------------------------------------------------------------------------	MINES
		else stuff "mine antipersonnel"		; ...........................................................................	Anti-Personnel Mines
			("explosion_grenade")
			{spawn "ex_he_size1_mud"}
		else stuff "mine antitank"		; ...........................................................................	Anti-Tank Mines
			("explosion_medium")
			{spawn "shockwave_sphere"}
			{spawn "ex_at_mine"}
;------------------------------------------------------------------------------------------------------------------------------------	OTHERS
		else stuff "shell smoke"												; All cannon Smoke shells
			{spawn "spherewater_small"}
		else stuff "flare marker"		; ...........................................................................	Special Flare ammo for mission scripts
			{spawn "spherewater_small"}
		else stuff "flare artillery"		; ...........................................................................	Flare for off-map Artillery
			{spawn "spherewater_small"}
		else stuff "glass ic"													; Ampulomet glass ball
			{spawn "spherewater_small"}
		}
)

(define "water_hits"
	{if min_mass 50
		{spawn "spherewater_big"}
	else min_mass 20
		{spawn "spherewater_medium"}
	else min_mass 5
		{spawn "spherewater_small"}
	else min_mass 0.1
		{spawn "spherewater_very_small"}
	else effector "human"
		{spawn "spherewater_big"}
	else effector "shell_large_rifle"
		{start_sound "hit/shell/shells_small/shared/Water/" use_position}
	else effector "shell_rifle"
		{start_sound "hit/shell/shells_small/shared/Water/" use_position}
	else effector "shell_9x19mm"
		{start_sound "hit/shell/shells_small/shared/Water/" use_position}
	else effector "shell_762x25mm"
		{start_sound "hit/shell/shells_small/shared/Water/" use_position}
	else effector "shell_792x33mm"
		{start_sound "hit/shell/shells_small/shared/Water/" use_position}
	}
)

{"shallow_water"
(include "\set\interaction_terrain\effects\effects-defines.inc")
	{on hit ("water_hits")}
	{on detonate
		("shallow_water_detonate")
		("water_detonate")
		("water_bullets")
	}
}

{"water"
	{on hit ("water_hits")}
	{on detonate
		("water_detonate")
		("water_bullets")
	}
}

{"underwater"
	{on hit ("water_hits")}
	{on detonate
		("water_detonate")
		("water_bullets")
	}
}

{"puddle"
(include "\set\interaction_terrain\effects\effects-defines.inc")
	{on hit
		("water_hits")
	}
	{on detonate
		("shallow_water_detonate")
		("water_detonate")
		("water_bullets")
	}
}

(define "swamp_terrain"
	{on hit ("water_hits")}
	{on bullet ("water_bullets")}
	{on detonate
		("water_detonate")
		("water_bullets")
	}
)

{"swamp"
	("swamp_terrain")
}

