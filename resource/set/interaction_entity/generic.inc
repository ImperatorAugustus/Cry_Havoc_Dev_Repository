{"generic"
(include "\set\interaction_terrain\effects\effects-defines.inc")
	{on bullet_hit
		{if not under_water
			{if material "flesh"
;		BULLETS
				{if stuff "bullet_fx size1"
					{spawn "blood_small"}
				else stuff "bullet_fx size2"
					{spawn "blood_small"}
					("sonic_crack")
				else stuff "bullet_fx size3"
					{spawn "blood_small"}
					("sonic_crack_medium")
;		20MM TO 40MM AA
				else stuff "auto ap"
					{spawn "blood_big"}
				else stuff "auto apbc"
					{spawn "blood_big"}
				else stuff "auto aphe"
					{spawn "blood_big"}
				else stuff "auto apcr"
					{spawn "blood_big"}
					("sonic_crack_medium")
				else stuff "auto he"
					{spawn "object_hit_fg_auto"}
					{spawn "blood"}
					("explosion_he_auto")
;		RIFLE GRENADES
				else stuff "rifle_grenade_at"
					{spawn "ex_air_minimum"}
					{spawn "blood"}
					("explosion_minimum")
				else stuff "rifle_grenade"
					{spawn "ex_air_minimum"}
					{spawn "blood"}
					("explosion_minimum")
;		AIRCRAFT BOMBS
				else stuff "bomb size1"
					{spawn "ex_air_large"}
					{spawn "blood_big"}
					("explosion_large")
				else stuff "bomb size2"
					{spawn "ex_air_large"}
					{spawn "blood_big"}
					("explosion_massive")
				else stuff "bomb size3"
					{spawn "ex_air_massive"}
					{spawn "blood_big"}
					("explosion_massive")
;		MORTARS
				else stuff "mortar size1 he"
					{spawn "ex_air_minimum"}
					{spawn "blood"}
					("explosion_minimum")
				else stuff "mortar size2 he"
					{spawn "ex_air_small"}
					{spawn "blood"}
					("explosion_small")
				else stuff "mortar size3 he"
					{spawn "ex_air_large"}
					{spawn "blood"}
					("explosion_large")
				else stuff "mortar_smoke"
					{spawn "ex_air_sm"}
					{spawn "mortar_smoke"}
					{spawn "blood"}
					{start_sound "detonation/explosion_smoke/mid/" use_position}
					{start_sound "detonation/explosion_smoke/far/" use_position}
;		SHOULDER FIRED HEAT
				else stuff "rocketlauncher heat_shell"
					{spawn "ex_air_small"}
					("explosion_HEAT")
;		HEAT SHELLS
				else stuff "shell size1 heat_shell"
					{spawn "ex_air_small"}
					("explosion_HEAT")
				else stuff "shell size2 heat_shell"
					{spawn "ex_air_medium"}
					("explosion_HEAT_large")
				else stuff "shell size3 heat_shell"
					{spawn "ex_air_large"}
					("explosion_HEAT_large")
;		HE SHELLS
				else stuff "shell size1 he"
					{spawn "ex_air_minimum"}
					("explosion_minimum")
					{spawn "blood_small"}
					{spawn "blood_big"}
				else stuff "shell size2 he"
					{spawn "ex_air_small"}
					("explosion_small")
					{spawn "blood_small"}
					{spawn "blood_big"}
				else stuff "shell size3 he"
					{spawn "ex_air_medium"}
					("explosion_medium")
					{spawn "blood_small"}
					{spawn "blood_big"}
				else stuff "shell size4 he"
					{spawn "ex_air_large"}
					("explosion_large")
					{spawn "blood_small"}
					{spawn "blood_big"}
				else stuff "shell size5 he"
					{spawn "ex_air_massive"}
					("explosion_massive")
					{spawn "blood_small"}
					{spawn "blood_big"}
				else stuff "shell size6 he"
					{spawn "ex_air_massive"}
					("explosion_massive")
					{spawn "blood_small"}
					{spawn "blood_big"}
;		AP & APCR SHELLS
				else stuff "size4"
					{spawn "ex_air_big2"}
					{spawn "blood_small"}
					{spawn "blood_big"}
				else stuff "shell"
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "flare marker"						; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
				}
;------------------------------------------------------------------------------------------------------------------------------------------------------------
			else material "steel"
;		BULLETS
				{if stuff "bullet_fx size1"
					{spawn "metal_hit_bul"}
				else stuff "bullet_fx size2"
					{spawn "metal_hit_bul"}
					("sonic_crack")
				else stuff "bullet_fx size3"
					{spawn "metal_hit_bul_at"}
					("sonic_crack_medium")
;		20MM TO 40MM AA

				else stuff "auto ap"
					{spawn "metal_hit_bul_zenite"}
				else stuff "auto apbc"
					{spawn "metal_hit_bul_zenite"}
				else stuff "auto aphe"
					{spawn "metal_hit_bul_zenite"}
					{blastwave c4 0.504 r0 0.2 r1 0.5 position}					; needs blast because ammo is pierce
					{blastwave c4 0.36 r0 0.75 r1 3.06 position}
				else stuff "auto apcr"
					{spawn "metal_hit_bul_at"}
					("sonic_crack_medium")
				else stuff "auto he"
					{spawn "metal_hit_he_auto"}
					("explosion_he_auto")
;		RIFLE GRENADES
				else stuff "rifle_grenade_at"
					{spawn "metal_hit_heat_small"}
					("explosion_grenade")
;		GRENADES
				else stuff "grenade size1"
					{spawn "metal_hit_he_minimum"}
					("explosion_minimum")
				else stuff "grenade size2"
					{spawn "metal_hit_he_minimum"}
					("explosion_grenade")
				else stuff "grenade size3"
					{spawn "metal_hit_he_small"}
					("explosion_small")
				else stuff "grenade size3"
					{spawn "metal_hit_he_medium"}
					("explosion_medium")
;		AIRCRAFT BOMBS
				else stuff "bomb size1"
					{spawn "metal_hit_he_large"}
					("explosion_large")
				else stuff "bomb size2"
					{spawn "metal_hit_he_large"}
					("explosion_massive")
				else stuff "bomb size3"
					{spawn "metal_hit_he_massive"}
					("explosion_massive")
;		MORTARS
				else stuff "mortar size1 he"
					{spawn "metal_hit_he_minimum"}
					("explosion_grenade")
				else stuff "mortar size2 he"
					{spawn "metal_hit_he_small"}
					("explosion_small")
				else stuff "mortar size3 he"
					{spawn "metal_hit_he_large"}
					("explosion_large")
				else stuff "mortar_smoke"
					{spawn "mortar_smoke"}
					{spawn "ex_air_sm"}
					{spawn "metal_hit_br"}
					{start_sound "detonation/explosion_smoke/mid/" use_position}
					{start_sound "detonation/explosion_smoke/far/" use_position}
					{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
					{start_sound "detonation/explosion_mechanical/terrain/Metal/" use_position}
;		HEAT SHELLS
				else stuff "heat_shell size1"		
					{spawn "metal_hit_heat_small"}
					{start_sound "hit/INT/HE/hit/small/" use_position}
					("explosion_HEAT")
					{blastwave c4 3 r0 2 r1 3.5 position}	
				else stuff "heat_shell size2"		
					{spawn "metal_hit_heat"}
					{start_sound "hit/INT/HE/hit/medium/" use_position}
					("explosion_HEAT_large")
					{blastwave c4 3 r0 2 r1 3.5 position}	
				else stuff "heat_shell size3"		
					{spawn "metal_hit_heat_big"}
					{start_sound "hit/INT/HE/hit/large/" use_position}
					("explosion_HEAT_large")
					{blastwave c4 3 r0 2 r1 3.5 position}	
				else stuff "heat_shell size4"		
					{spawn "metal_hit_heat_big"}
					{start_sound "hit/INT/HE/hit/large/" use_position}
					("explosion_HEAT_large")
;		HE SHELLS
				else stuff "shell size1 he"
					{spawn "metal_hit_he_minimum"}
					("explosion_minimum")
				else stuff "shell size2 he"
					{spawn "metal_hit_he_small"}
					("explosion_small")
				else stuff "shell size3 he"
					{spawn "metal_hit_he_medium"}
					("explosion_medium")
				else stuff "shell size4 he"
					{spawn "shockwave_sphere"}
					{spawn "metal_hit_he_large"}
					("explosion_large")
				else stuff "shell size5"
					{spawn "shockwave_sphere"}
					{spawn "metal_hit_he_massive"}
					("explosion_massive")
				else stuff "shell size6"
					{spawn "shockwave_sphere"}
					{spawn "metal_hit_he_massive"}
					("explosion_massive")
;		AP & APCR SHELLS
				else stuff "shell size1 hasfiller"
					{spawn "metal_hit_br_small"}
				else stuff "shell size2 hasfiller"
					{spawn "metal_hit_br"}
					("explosion_ap")
				else stuff "shell size3 hasfiller"
					{spawn "metal_hit_br_big"}
					("explosion_ap")
				else stuff "shell size4 hasfiller"
					{spawn "metal_hit_br_big"}
					("explosion_ap")
				else stuff "shell size1 apcr"
					{spawn "metal_hit_br_small_ap"}
				else stuff "shell size2 apcr"
					{spawn "metal_hit_br_ap"}
				else stuff "shell size3 apcr"
					{spawn "metal_hit_br_big_ap"}
				else stuff "shell size4 apcr"
					{spawn "metal_hit_br_big_ap"}
;		OTHERS

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "metal_hit_bul"}
				else stuff "flare artillery"							; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "metal_hit_bul"}
				else stuff "flame"

				else
					{spawn "metal_hit_br_small"}
				}
;---------------------------------------------------------------------------------------------------------------------------------------------------------
			else material "wood"
;		BULLETS
				{if stuff "bullet_fx size1"
					{spawn "wood_hit_bul"}
				else stuff "bullet_fx size2"
					{spawn "wood_hit_bul"}
					("sonic_crack")
				else stuff "bullet_fx size3"
					{spawn "wood_hit_bul"}
					("sonic_crack_medium")
;		20MM TO 40MM AA
				else stuff "auto ap"
					{spawn "wood_hit_br_auto"}
				else stuff "auto apbc"
					{spawn "wood_hit_br_auto"}
				else stuff "auto aphe"
					{spawn "wood_hit_br_auto"}
				else stuff "auto apcr"
					{spawn "wood_hit_br_auto"}
					("sonic_crack_medium")
				else stuff "auto he"
					{spawn "object_hit_fg_auto"}
					("explosion_he_auto")
;		AIRCRAFT BOMBS
				else stuff "bomb size1"
					{spawn "wood_hit_he_large"}
					{spawn "shockwave_sphere"}
					("explosion_large")
				else stuff "bomb size2"
					{spawn "wood_hit_he_large"}
					{spawn "shockwave_sphere"}
					("explosion_massive")
				else stuff "bomb size3"
					{spawn "wood_hit_he_massive"}
					{spawn "shockwave_sphere"}
					("explosion_massive")
;		MORTARS
				else stuff "mortar size1 he"
					{spawn "wood_hit_he_minimum"}
					("explosion_grenade")
				else stuff "mortar size2 he"
					{spawn "wood_hit_he_small"}
					{spawn "shockwave_sphere"}
					("explosion_small")
				else stuff "mortar_smoke"
					{spawn "mortar_smoke"}
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}
					{start_sound "detonation/explosion_smoke/mid/" use_position}
					{start_sound "detonation/explosion_smoke/far/" use_position}
					{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
					{start_sound "detonation/explosion_mechanical/terrain/Wood/" use_position}
				else stuff "mortar size3 he"
					{spawn "wood_hit_he_large"}
					{spawn "shockwave_sphere"}
					("explosion_large")
;		SHOULDER FIRED HEAT
				else stuff "rocketlauncher heat_shell"
					{spawn "wood_hit_he_small"}
					("explosion_HEAT")
					{blastwave c4 3 r0 2 r1 3.5 position}							; needs blast because ammo is pierce
;		HEAT SHELLS
				else stuff "shell size1 heat_shell"
					{spawn "wood_hit_he_small"}
					("explosion_HEAT")
				else stuff "shell size2 heat_shell"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_medium"}
					("explosion_HEAT")
				else stuff "shell size3 heat_shell"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_large"}
					("explosion_HEAT_large")
				else stuff "shell size4 heat_shell"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_large"}
					("explosion_HEAT_large")
;		HE SHELLS
				else stuff "shell size1 he"
					{spawn "wood_hit_he_minimum"}
					("explosion_minimum")
				else stuff "shell size2 he"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_small"}
					("explosion_small")
				else stuff "shell size3 he"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_medium"}
					("explosion_medium")
				else stuff "shell size4 he"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_large"}
					("explosion_large")
				else stuff "shell size5"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_massive"}
					("explosion_massive")
				else stuff "shell size6"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_massive"}
					("explosion_massive")
;		AP & APCR SHELLS
				else stuff "shell size1"
					{spawn "wood_hit_br_auto"}
				else stuff "shell size2"
					{spawn "wood_hit_br_small"}
				else stuff "shell size3"
					{spawn "wood_hit_br"}
				else stuff "shell size4"
					{spawn "wood_hit_br_big"}
;		OTHERS

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "wood_hit_bul"}
				else stuff "flare artillery"							; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "wood_hit_bul"}
				else stuff "flame"

				else
					{spawn "wood_hit_br"}
				}
;------------------------------------------------------------------------------------------------------------------------------------------------------------
			else material "concrete"
;		BULLETS
				{if stuff "bullet_fx size1"
					{spawn "stone_hit_bul"}
				else stuff "bullet_fx size2"
					{spawn "stone_hit_bul"}
					("sonic_crack")
				else stuff "bullet_fx size3"
					{spawn "stone_hit_br_auto"}
					("sonic_crack_medium")
;		20MM TO 40MM AA
				else stuff "auto ap"
					{spawn "stone_hit_br_auto"}
				else stuff "auto apbc"
					{spawn "stone_hit_br_auto"}
				else stuff "auto apha"
					{spawn "stone_hit_br_auto"}
				else stuff "auto apcr"
					{spawn "stone_hit_br_auto"}
					("sonic_crack_medium")
				else stuff "auto he"
					{spawn "object_hit_fg_auto"}
					("explosion_he_auto")
;		RIFLE GRENADES
				else stuff "rifle_grenade"
					{spawn "stone_hit_he_minimum"}
					("explosion_minimum")
				else stuff "rifle_grenade_at"
					{spawn "stone_hit_he_minimum"}
					("explosion_minimum")
;		AIRCRAFT BOMBS
				else stuff "bomb size1"
					{spawn "stone_hit_he_large"}
					("explosion_large")
				else stuff "bomb size2"
					{spawn "stone_hit_he_large"}
					("explosion_massive")
				else stuff "bomb size3"
					{spawn "stone_hit_he_massive"}
					("explosion_massive")
;		MORTARS
				else stuff "mortar size1 he"
					{spawn "stone_hit_he_minimum"}
					("explosion_minimum")
				else stuff "mortar size2 he"
					{spawn "stone_hit_he_small"}
					("explosion_small")
				else stuff "mortar_smoke"
					{spawn "mortar_smoke"}
					{spawn "ex_air_sm"}
					{spawn "stone_hit_bul"}
					{start_sound "detonation/explosion_smoke/mid/" use_position}
					{start_sound "detonation/explosion_smoke/far/" use_position}
					{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
					{start_sound "detonation/explosion_mechanical/terrain/Wood/" use_position}
				else stuff "mortar size3 he"
					{spawn "stone_hit_he_large"}
					("explosion_large")
					{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
;		SHOULDER FIRED HEAT
				else stuff "rocketlauncher heat_shell"
					{spawn "stone_hit_he_small"}
					("explosion_HEAT")
					{start_sound "detonation/explosion_mechanical/terrain/Rock/" use_position}
					{blastwave c4 3 r0 2 r1 3.5 position}							; needs blast because ammo is pierce
;		HEAT SHELLS
				else stuff "shell size1 heat_shell"
					{spawn "stone_hit_he_medium"}
					("explosion_HEAT")
				else stuff "shell size2 heat_shell"
					{spawn "stone_hit_he_medium"}
					("explosion_HEAT")
				else stuff "shell size3 heat_shell"
					{spawn "stone_hit_he_large"}
					("explosion_HEAT_large")
				else stuff "shell size4 heat_shell"
					{spawn "stone_hit_he_large"}
					("explosion_HEAT_large")
;		HE SHELLS
				else stuff "shell size1 he"
					{spawn "stone_hit_he_minimum"}
					("explosion_minimum")
				else stuff "shell size2 he"
					{spawn "stone_hit_he_small"}
					("explosion_small")
				else stuff "shell size3 he"
					{spawn "stone_hit_he_medium"}
					{spawn "shockwave_sphere"}
					("explosion_medium")
				else stuff "shell size4 he"
					{spawn "stone_hit_he_large"}
					{spawn "shockwave_sphere"}
					("explosion_large")
				else stuff "shell size5"
					{spawn "shockwave_sphere"}
					{spawn "stone_hit_he_massive"}
					("explosion_massive")
				else stuff "shell size6"
					{spawn "shockwave_sphere"}
					{spawn "stone_hit_he_massive"}
					("explosion_massive")
;		AP & APCR SHELLS
				else stuff "shell size1"
					{spawn "stone_hit_br_auto"}
				else stuff "shell size2"
					{spawn "stone_hit_br_small"}
				else stuff "shell size3"
					{spawn "stone_hit_br"}
				else stuff "shell size4"
					{spawn "stone_hit_br_big"}
;		OTHERS

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "stone_hit_bul"}
				else stuff "flare artillery"							; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "stone_hit_bul"}
				else stuff "flame"

				else
					{spawn "stone_hit_br"}
				}
;------------------------------------------------------------------------------------------------------------------------------------------------------------
			else material "straw"
;		BULLETS
				{if stuff "bullet_fx size1"
					{spawn "wood_hit_bul"}
				else stuff "bullet_fx size2"
					{spawn "wood_hit_bul"}
					("sonic_crack")
				else stuff "bullet_fx size3"
					{spawn "wood_hit_bul"}
					("sonic_crack_medium")
;		20MM TO 40MM AA
				else stuff "auto ap"
					{spawn "wood_hit_br_auto"}
				else stuff "auto apbc"
					{spawn "wood_hit_br_auto"}
				else stuff "auto aphe"
					{spawn "wood_hit_br_auto"}
				else stuff "auto apcr"
					{spawn "wood_hit_br_auto"}
					("sonic_crack_medium")
				else stuff "auto he"
					{spawn "object_hit_fg_auto"}
					("explosion_he_auto")
;		AIRCRAFT BOMBS
				else stuff "bomb size1"
					{spawn "wood_hit_he_large"}
					{spawn "shockwave_sphere"}
					("explosion_large")
				else stuff "bomb size2"
					{spawn "wood_hit_he_large"}
					{spawn "shockwave_sphere"}
					("explosion_massive")
				else stuff "bomb size3"
					{spawn "wood_hit_he_massive"}
					{spawn "shockwave_sphere"}
					("explosion_massive")
;		MORTARS
				else stuff "mortar size1 he"
					{spawn "wood_hit_he_minimum"}
					("explosion_grenade")
				else stuff "mortar size2 he"
					{spawn "wood_hit_he_small"}
					{spawn "shockwave_sphere"}
					("explosion_small")
				else stuff "mortar_smoke"
					{spawn "mortar_smoke"}
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}
					{start_sound "detonation/explosion_smoke/mid/" use_position}
					{start_sound "detonation/explosion_smoke/far/" use_position}
					{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
					{start_sound "detonation/explosion_mechanical/terrain/Wood/" use_position}
				else stuff "mortar size3 he"
					{spawn "wood_hit_he_large"}
					{spawn "shockwave_sphere"}
					("explosion_large")
;		SHOULDER FIRED HEAT
				else stuff "rocketlauncher heat_shell"
					{spawn "wood_hit_he_small"}
					("explosion_HEAT")
					{blastwave c4 3 r0 2 r1 3.5 position}							; needs blast because ammo is pierce
;		HEAT SHELLS
				else stuff "shell size1 heat_shell"
					{spawn "wood_hit_he_small"}
					("explosion_HEAT")
				else stuff "shell size2 heat_shell"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_medium"}
					("explosion_HEAT")
				else stuff "shell size3 heat_shell"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_large"}
					("explosion_HEAT_large")
				else stuff "shell size4 heat_shell"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_large"}
					("explosion_HEAT_large")
;		HE SHELLS
				else stuff "shell size1 he"
					{spawn "wood_hit_he_minimum"}
					("explosion_minimum")
				else stuff "shell size2 he"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_small"}
					("explosion_small")
				else stuff "shell size3 he"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_medium"}
					("explosion_medium")
				else stuff "shell size4 he"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_large"}
					("explosion_large")
				else stuff "shell size5"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_massive"}
					("explosion_massive")
				else stuff "shell size6"
					{spawn "shockwave_sphere"}
					{spawn "wood_hit_he_massive"}
					("explosion_massive")
;		AP & APCR SHELLS
				else stuff "shell size1"
					{spawn "wood_hit_br_auto"}
				else stuff "shell size2"
					{spawn "wood_hit_br_small"}
				else stuff "shell size3"
					{spawn "wood_hit_br"}
				else stuff "shell size4"
					{spawn "wood_hit_br_big"}
;		OTHERS

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "wood_hit_bul"}
				else stuff "flare artillery"							; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "wood_hit_bul"}
				else stuff "flame"

				else
					{spawn "wood_hit_br"}
				}
;------------------------------------------------------------------------------------------------------------------------------------------------------------
			else material "sand"
;		BULLETS
				{if stuff "bullet_fx size1"
					{spawn "sand_hit_bul_sm"}
				else stuff "bullet_fx size2"
					{spawn "sand_hit_bul_sm"}
					("sonic_crack")
				else stuff "bullet_fx size3"
					{spawn "sand_hit_zenite"}
					("sonic_crack_medium")
;		20MM TO 40MM AA
				else stuff "auto ap"
					{spawn "sand_hit_br_auto"}
				else stuff "auto apbc"
					{spawn "sand_hit_br_auto"}
				else stuff "auto aphe"
					{spawn "sand_hit_br_auto"}
				else stuff "auto apcr"
					{spawn "sand_hit_br_auto"}
					("sonic_crack_medium")
				else stuff "auto he"
					{spawn "object_hit_fg_auto"}
					("explosion_he_auto")
;		RIFLE GRENADES
				else stuff "rifle_grenade"
					{spawn "sand_hit_he_minimum"}
					("explosion_minimum")
				else stuff "rifle_grenade_at"
					{spawn "sand_hit_he_minimum"}
					("explosion_minimum")
;		AIRCRAFT BOMBS
				else stuff "bomb size1"
					{spawn "sand_hit_he_large"}
					("explosion_large")
				else stuff "bomb size2"
					{spawn "sand_hit_he_massive"}
					("explosion_massive")
				else stuff "bomb size3"
					{spawn "sand_hit_he_massive"}
					("explosion_massive")
;		MORTARS
				else stuff "mortar size1 he"
					{spawn "sand_hit_he_minimum"}
					("explosion_grenade")
				else stuff "mortar size2 he"
					{spawn "sand_hit_he_small"}
					("explosion_small")
				else stuff "mortar_smoke"
					{spawn "mortar_smoke"}
					{spawn "ex_air_sm"}
					{spawn "sand_hit_bul"}
					{start_sound "detonation/explosion_smoke/mid/" use_position}
					{start_sound "detonation/explosion_smoke/far/" use_position}
					{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
				else stuff "mortar size3 he"
					{spawn "sand_hit_he_large"}
					("explosion_large")
;		SHOULDER FIRED HEAT
				else stuff "rocketlauncher heat_shell"
					{spawn "sand_hit_he_small"}
					("explosion_HEAT")
					{blastwave c4 3 r0 2 r1 3.5 position}							; needs blast because ammo is pierce
;		HEAT SHELLS
				else stuff "shell size1 heat_shell"
					{spawn "sand_hit_he_medium"}
					("explosion_HEAT")
				else stuff "shell size2 heat_shell"
					{spawn "sand_hit_he_medium"}
					("explosion_HEAT")
				else stuff "shell size3 heat_shell"
					{spawn "sand_hit_he_large"}
					("explosion_HEAT_large")
				else stuff "shell size4 heat_shell"
					{spawn "sand_hit_he_large"}
					("explosion_HEAT_large")
;		HE SHELLS
				else stuff "shell size1 he"
					{spawn "sand_hit_he_minimum"}
					("explosion_minimum")
				else stuff "shell size2 he"
					{spawn "sand_hit_he_small"}
					("explosion_small")
				else stuff "shell size3 he"
					{spawn "sand_hit_he_medium"}
					("explosion_medium")
				else stuff "shell size4 he"
					{spawn "sand_hit_he_large"}
					("explosion_large")
				else stuff "shell size5"
					{spawn "shockwave_sphere"}
					{spawn "sand_hit_he_massive"}
					("explosion_massive")
				else stuff "shell size6"
					{spawn "shockwave_sphere"}
					{spawn "sand_hit_he_massive"}
					("explosion_massive")
;		AP & APCR SHELLS
				else stuff "shell size1"
					{spawn "sand_hit_br_auto"}
				else stuff "shell size2"
					{spawn "sand_hit_br_small"}
				else stuff "shell size3"
					{spawn "sand_hit_br"}
				else stuff "shell size4"
					{spawn "sand_hit_br_big"}
;		OTHERS

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "sand_hit_bul"}
				else stuff "flare artillery"							; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "sand_hit_bul"}
				else stuff "flame"

				else
					{spawn "sand_hit_br"}
				}
;------------------------------------------------------------------------------------------------------------------------------------------------------------
			else material "glass"
				{if stuff "flame"
				
				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "glass_hit"}
				else
					{spawn "glass_hit"}
				}
;------------------------------------------------------------------------------------------------------------------------------------------------------------
			else material "ice"
				{if stuff "shell he"
					{spawn "ex_mort_sm_snow"}

				else stuff "shell apcr"
					{spawn "snow_hit_small"}
					
				else stuff "flame"
				
				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
				else
					{spawn "snow_hit_small"}
				}
;------------------------------------------------------------------------------------------------------------------------------------------------------------
			else material "fabric"
				{if stuff "flame"
				
				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
				else
					{spawn "fabric_hit_bul"}
				}
			}
		}
	}
}