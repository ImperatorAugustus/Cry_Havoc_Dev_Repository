;/*=========== Generic Weapon Settings Begin ===========*/

(define "shell_fx"
	{"stuff weapon %tag"
		{on spawn
			{add_view "%shell" "shell" "FXshell"}
		}
	}
)

("shell_fx" tag(pistol_shell)		shell(shell_pistol))
("shell_fx" tag(pistol2_shell)		shell(shell_pistol2))
("shell_fx" tag(inter_shell)		shell(shell_inter))
("shell_fx" tag(rifle_shell)		shell(shell_rifles))
("shell_fx" tag(hmg_shell)		shell(shell_hmgun))
("shell_fx" tag(ptr_shell)		shell(shell_ptr))
("shell_fx" tag(mgun_shell)		shell(shell_mgun))
("shell_fx" tag(shotgun_shell)		shell(shell_shotgun))

(define "flash_fx"
	{"stuff weapon %tag"
		{on spawn
			{if not prop "silenced"
				{add_view "%flash" "flashbarrel" "foresight%foresight"}
			else
				{add_view "flash_gun_silencer" "flashbarrel" "foresight%foresight"}
			}
		}
	}
)

("flash_fx" tag(pistol)			flash(flash_gun_small)	foresight(3))
("flash_fx" tag(smg)			flash(flash_gun_small)	foresight(11))
("flash_fx" tag(rifle)			flash(flash_gun_rifle)	foresight(12))
("flash_fx" tag(mgun)			flash(flash_gun_big)	foresight(14))
("flash_fx" tag(at_rifle)		flash(flash_gun_atrifle)foresight(18))
("flash_fx" tag(shotgun)		flash(flash_shotgun)	foresight(3))

(define "ejectsmoke_fx"
	{"stuff weapon %tag"
		{on spawn
			{add_view "%ejectsmoke" "ejectsmoke" "FXshell"}
		}
	}
)

("ejectsmoke_fx" tag(smg)		ejectsmoke(ejectsmoke_small))
("ejectsmoke_fx" tag(rifle)		ejectsmoke(ejectsmoke_small))
("ejectsmoke_fx" tag(mgun)		ejectsmoke(ejectsmoke_big))

(define "holster_fx"
	{"stuff weapon %tag"
		{on spawn
			{link_sound "holster"	"human/holster/%sound"}
		}
	}
)

("holster_fx" tag(pistol)			sound(pistol))
("holster_fx" tag(smg)				sound(weapon))
("holster_fx" tag(rifle)			sound(weapon))
("holster_fx" tag(mgun)				sound(weapon))
("holster_fx" tag(shotgun)			sound(weapon))
("holster_fx" tag(ptr)				sound(big))
("holster_fx" tag(bazooka)			sound(big))
("holster_fx" tag(flame_thrower)	sound(flame))
("holster_fx" tag(melee)			sound(knife))

(define "sound_fx"
	{"stuff weapon %tag"
		{on spawn
			{if not prop "silenced"
				{link_sound "bkg"	"weapon/shot/bkg/gun/%sound"}
			}
		}
	}
)

("sound_fx" tag(pistol)		sound(smg))
("sound_fx" tag(smg)		sound(smg))
("sound_fx" tag(rifle)		sound(rifle))
("sound_fx" tag(mgun)		sound(mg))
("sound_fx" tag(at_rifle)	sound(hmg))
("sound_fx" tag(shotgun)	sound(rifle))

{"stuff weapon"
	{on "drop_item"}			;// when item is not in hand and is dropped from inventory.
	
	{on "fire"
	    	{play_sound "mid"}
	    	{play_sound "far"}
		{ani_play "recoil"}
		{view show	"flashbarrel"}
		{view start	"flashbarrel"}
		{delay 0.2 "fire"
			{view hide	"flashbarrel"}
			{view pause	"flashbarrel"}
		}
	}
	{on "link_human"
		{play_sound "holster"}
		{delay 0.2
			{ani_play "prepare"}
		}
	}
	{on "unlink_human"
		{ani_play "prepare" -1}
	}
	{on "case_eject"
		{view start "shell"}
		{view show	"ejectsmoke"}
		{view start	"ejectsmoke"}
		{delay 0.1 "shell"
			{view pause "shell"}
			{view hide	"ejectsmoke"}
			{view pause	"ejectsmoke"}
		}
	}
	{on "weapon_reload"
		{kill_delay "bolt_action"}
		{ani_play "reload"}
		{call "magazine_delay"}
	}
	(define "magazine"
		{on "magazine_delay" %override
			{delay %cut
				{view hide "bullet"}
				{tear "piece_tiny_steel" bone "magazine" copy
					%impulse
				}
				{delay 0
					{view hide "magazine"}
					{delay %show
						{view show "magazine"}
						{view show "bullet"}
					}
				}
			}
		}
	)
	("magazine" cut(0) show(1.8) override() impulse({impulse up -0.01 com}))

	(define "drop"
		{on ground_hit %override
			{if terrain_fx "road"
				{start_sound "weapon/drop/%material/rock"}
			
			else terrain_fx "ice"
				{start_sound "weapon/drop/%material/rock"}
			
			else terrain_fx "snow"
				{start_sound "weapon/drop/%material/snow"}
			
			else terrain_fx "sand"
				{start_sound "weapon/drop/%material/snow"}
			
			else terrain_fx "bridge_wood"
				{start_sound  "weapon/drop/%material/wood"}
			
			else terrain_fx "shallow_water"

			else terrain_fx "water"

			else
				{start_sound "weapon/drop/%material/ground"}
			}
		}
	)
	("drop" material(metal) override())
}

{"stuff weapon wood_stock"
	("drop" material(wood) override(overload))
}

{"stuff weapon auto_eject"
	{on "fire"
		{call "case_eject"}
	}
}

{"stuff weapon bolt_action"
	{on "fire"
	{delay 0.85
		{call "case_eject"}
	}
		{delay 0.5 "bolt_action"
			{ani_play "bolt_action" 1.2}
			{play_sound "open_bolt"}
			{delay 0.36
				    {play_sound "close_bolt"}
			}
		}
	}
}

{"stuff weapon shotgun"
	{on "weapon_reload" overload
		{delay 0.5
			{ani_play "reload"}
		}
		(define "double_shot"
			{delay %0
				{tear "piece_small_steel" bone "shell%1" copy
					{impulse up -0.01}
				}
				{delay 0
					{view hide "shell%1"}
					{delay 2.0
						{view show "shell%1"}
					}
				}
			}
		)
		("double_shot" args 0.9 1)
		("double_shot" args 1.00 2)
	}
}

{"stuff weapon flare_gun"
	{on "weapon_reload" overload
		{delay 0.5
			{ani_play "reload"}
		}

		{delay 1
			{tear "piece_small_steel" bone "flare" copy
				{impulse up -0.01}
			}
			{delay 0
				{view hide "flare"}
				{delay 1.5
					{view show "flare"}
				}
			}
		}
	}
}


(define "flame_fx"
	{"stuff weapon flame_thrower %tag"
		{on spawn
			{add_view "flamer_fire"			"flame"	"foresight3"}
			{add_view "flamer_fire_barrel"	"fire"	"foresight3"}

			{link_sound "start"	"weapon/shot/flame/handheld/flamer_start"}
			{link_sound "loop"	"weapon/shot/flame/handheld/flamer_loop"}
			{link_sound "end"	"weapon/shot/flame/handheld/flamer_stop"}
		}
		{on "start_burst"
			{play_sound "start"}
			{delay 0.1 "loop"
				{play_sound "loop" 1}
			}
		}
		{on "end_burst"
			{kill_delay "loop"}
			{play_sound "end"}
			{stop_sound "loop"}
		}
		
		{on "link_human"
			{view show	"fire"}
			{view start	"fire"}
		}
		{on "unlink_human"
			{view pause	"fire"}
		}
		{on "fire" overload
			{spawn "%flame" "foresight3" x
				{impulse forward 30 rnd_dir 0.01}
				{gravity 1}
				{linear_damping 0}
			}
			{view start "flame"}
			{kill_delay "fire"}
			{delay 0.1 "fire"
				{view pause "flame"}
			}
		}
	}
)

("flame_fx" tag(range_30)		flame(fx_piece_flame_30))
("flame_fx" tag(range_40)		flame(fx_piece_flame_40))
;========================================= BEGIN WEAPON SOUND DEFINES========================================
;----------------------------------------------	GERMAN WEAPONS ----------------------------------------------
{"stuff weapon FG42"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/GER/FG42/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/FG42/far/"}
	}
}
{"stuff weapon G41"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/GER/G41/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/G41/far/"}
	}
}
{"stuff weapon G43"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/GER/G41/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/G41/far/"}
	}
}
{"stuff weapon KAR98K"
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/KAR98K/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/KAR98K/"}
		{link_sound "mid"		"weapon/shot/small_arms/GER/Kar98k/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/Kar98k/far/"}
	}
}
{"stuff weapon MG34"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/GER/MG34/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/MG34/far/"}
	}
}
{"stuff weapon MG42"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/GER/MG42/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/MG42/far/"}
	}
}
{"stuff weapon MP40"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/GER/MP40/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/MP40/far/"}
	}
}
{"stuff weapon P08"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/GER/P08/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/P08/far/"}
	}
}
{"stuff weapon P38"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/GER/P38/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/P38/far/"}
	}
}
{"stuff weapon Panzerfaust"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/GER/Panzerfaust/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/Panzerfaust/far/"}
	}
}
{"stuff weapon StG44"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/GER/StG44/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/StG44/far/"}
	}
}
;----------------------------------------------	SOVIET UNION WEAPONS ----------------------------------------------
{"stuff weapon DP27"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/RUS/DP27/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/RUS/DP27/far/"}
	}
}
{"stuff weapon M9130"
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M91-30/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M91-30/"}
		{link_sound "mid"		"weapon/shot/small_arms/RUS/M1891-30/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/RUS/M1891-30/far/"}
	}
}
{"stuff weapon M1895"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/RUS/M1895/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/RUS/M1895/far/"}
	}
}
{"stuff weapon PPSH41"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/RUS/PPSH41/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/RUS/PPSH41/far/"}
	}
}
{"stuff weapon PPS43"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/RUS/PPS43/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/RUS/PPS43/far/"}
	}
}
{"stuff weapon SVT40"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/RUS/SVT40/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/RUS/SVT40/far/"}
	}
}
{"stuff weapon TT33"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/RUS/TT33/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/RUS/TT33/far/"}
	}
}
;----------------------------------------------	UNITED KINGDOM WEAPONS ---------------------------------------------
{"stuff weapon Bren_MkII"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/UK/Bren_MkII/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/UK/Bren_MkII/far/"}
	}
}
{"stuff weapon Lee_Enfield"
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/Lee_Enfield/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/Lee_Enfield/"}
		{link_sound "mid"		"weapon/shot/small_arms/UK/Lee_Enfield/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/UK/Lee_Enfield/far/"}
	}
}
{"stuff weapon PIAT"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/UK/PIAT/mid/"}
	}
}
{"stuff weapon Sten"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/UK/Sten/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/UK/Sten/far/"}
	}
}
;----------------------------------------------	UNITED STATES WEAPONS ----------------------------------------------
{"stuff weapon M1_Carbine"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/USA/M1_Carbine/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/USA/M1_Carbine/far/"}
	}
}
{"stuff weapon M1_Garand"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/USA/M1_Garand/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/USA/M1_Garand/far/"}
	}
}
{"stuff weapon M1_Thompson"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/USA/M1_Thompson/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/USA/M1_Thompson/far/"}
	}
}
{"stuff weapon M1903A3"
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M1903A3/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M1903A3/"}
		{link_sound "mid"		"weapon/shot/small_arms/USA/M1903A3/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/USA/M1903A3/far/"}
	}
}
{"stuff weapon M1911A1"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/USA/M1911A1/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/USA/M1911A1/far/"}
	}
}
{"stuff weapon M1918A2_BAR"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/USA/M1918_BAR/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/USA/M1918_BAR/far/"}
	}
}
{"stuff weapon M1919A4"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/USA/M1919A4/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/USA/M1919A4/far/"}
	}
}
{"stuff weapon M2HB"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/USA/M2HB/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/USA/M2HB/far/"}
	}
}
{"stuff weapon M3_Greasegun"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/USA/M3_Greasegun/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/USA/M3_Greasegun/far/"}
	}
}
;----------------------------------------------	SHARED WEAPONS ----------------------------------------------
{"stuff weapon PTR"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/Shared/AT_Rifle/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/Shared/AT_Rifle/far/"}
	}
}
{"stuff weapon Rocket_Launcher"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/Shared/Rocket_Launcher/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/Shared/Rocket_Launcher/far/"}
	}
}
{"stuff weapon Rifle_Grenade"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/Shared/Rifle_Grenade/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/GER/P38/far/"}
	}
}
{"stuff weapon shotgun"
	{on spawn
		{link_sound "mid"		"weapon/shot/small_arms/Shared/Shotgun/mid/"}
		{link_sound "far"		"weapon/shot/small_arms/Shared/Shotgun/far/"}
	}
}
;========================================= END WEAPON SOUND DEFINES========================================
{"stuff weapon rocketlauncher"
	{on "fire"
		{spawn "bazooka_shot"	"fxshot" x}
		{delay 0.05
			{start_sound "detonation/explosion_mechanical/shockwave/short/" use_position}
		}
		{with_effector
			{if terrain_fx "water"
			else terrain_fx "shallow_water"
			else terrain_fx "mud"
			else terrain_fx "snow"
				{spawn "bazooka_snow"	"basis" x}
			else terrain_fx "ice"
				{spawn "bazooka_snow"	"basis" x}
			else
				{spawn "bazooka_dust"	"basis" x}
			}
		}
	}
	{on "link_human" overload
		{delay 1.3
			{ani_play "prepare"}
		}
	}
}

{"stuff weapon bipod"			;// weapons with bipods
	{on spawn 
		{ani_wind "bipod_open" begin}
	}
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link" 					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
}

;/*=========== Generic Weapon Settings End ===========*/


;/*=========== Sepcific Weapons Begin ===========*/

{"stuff weapon mp40"					;// props added to all MP40 variants
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon stg44"					;// props added to all stg44 variants
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon ppd40"
	("magazine" cut(1.85) show(1.75) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon ppsh41_drum"
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon ppsh41_stick"
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon pps43"
	("magazine" cut(0.85) show(1.95) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon dp_bipod"
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}

{"stuff weapon dt"					;// props added to all DT variants
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}

{"stuff weapon mg34_doubledrum"
	("magazine" cut(1) show(2.25) override(overload) impulse({impulse up 0.5 forward 0.9 0.1}))
}

{"stuff weapon mg34_drum"
	("magazine" cut(1) show(1.95) override(overload) impulse({impulse up 0.4 forward 0.9 0.1}))
}

{"stuff weapon mg42_drum"
	("magazine" cut(1) show(1.95) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}

{"stuff weapon svt"					;// props added to all SVT variants
	("magazine" cut(1.75) show(2.1) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon ptrd"
	{on "weapon_reload" overload
		{delay 4.2
			{ani_play "reload"}
		}
	}
}

{"stuff weapon ptrs"
	{on "weapon_reload" overload
		{delay 0.5
			{kill_delay "bolt_action"}
			{ani_play "reload"}
			{view hide "bullet"}
			{call "magazine_delay"}
		}
	}
	("magazine" cut(0.1) show(2.9) override(overload) impulse({impulse up -0.01}))
}

;/*=========== Sepcific Weapons End ===========*/
;/*=========== Weapon Texmods Begin ===========*/

{"stuff weapon tex_mod"
	{on spawn
		{if rand 0.167 {delay 0.1 {tex_mod "tex_var1"}}
		else rand 0.20 {delay 0.1 {tex_mod "tex_var2"}}
		else rand 0.25 {delay 0.1 {tex_mod "tex_var3"}}
		else rand 0.333 {delay 0.1 {tex_mod "tex_var4"}}
		else rand 0.50 {delay 0.1 {tex_mod "tex_var5"}}
		}
	}
}
{"stuff weapon tex_mod2"
	{on spawn
		{if rand 0.333 {delay 0.1 {tex_mod "tex_var1"}}
		else rand 0.5 {delay 0.1 {tex_mod "tex_var2"}}
		}
	}
}

;/*=========== Weapon Texmods End ===========*/