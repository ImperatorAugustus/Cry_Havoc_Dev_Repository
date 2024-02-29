;MAIN_MENU BEGIN ;to change jam ratio for different weapon types such as smg mgun search set_weapontype

{on "jam_enable"
	{set "gun_jamming_enabled" 1} ;Disable/Enable Gun Jamming.
}

{on "gun_jam_mod_menu"

;Animations
	{set "cant_move" 0} ;stops the unit from moving to prevent the animation from conflicting with the movement. I MUST FIX THIS X_x.
	{set "jam_fix_animations" 0} ;units get a reloading animation when trying to fix the weapon jam.

;Random/Enviroment Jam Modifiers	
	{set "ingame_jam_modifiers" 1} ;randomly gives decreased or increased proabability of jamming after it is fixed.
	{set "winter_season" 0} ;makes all guns jam +.0065% more. ;\ 
	{if not "winter_season" ;siberia_winter_season can be enabled if winter_season is disabled ; \
	{set "siberia_winter_season" 0}} ;makes all guns jam +.0155% more. must have Winter_Season disabled for it to work.
	{set "winter_sound" 1} ;winter sound misc. if winter_season's is enabled ;

;Terrain Influence
	{set "terrain_influence" 1} ;when soldiers are LYING DOWN, on snow or swamps,sand,mud, and shallow water they will be more at risk of jamming until they squat or stand up.

	{set "random_fix_timer" 1} ;Random jam fix timers disable to set to manual timer search for set_manualtimer

;HangFire
	{set "hangfire" 1} ;randomly forces a delay to gunfire, could be potentially dangerous, as the surplus ammo could damage the barrel doing damage to the soldier's hands.
	{if "winter_season" 
		{if rand 0.0065 
			{tags add "js"}{tags add "winterjam"} 
		}
	}
	{if "siberia_winter_season" 
		{if rand 0.0155 
			{tags add "js"}{tags add "winterjam"}
		}
	}
}
 
{on "jam_modifiers_menu" 
	{if "ingame_jam_modifiers" 
		{if tagged "jamca" 
			{if tagged "js" 
				{if rand 0.7 
					{tags remove "js"}
					{tags remove "winterjam"}
					{delay 0.2
						{damage_report "body" "<c(00ff18)>."}
					}
				}
			}
		}
	} ;decrease jam
	{if "ingame_jam_modifiers" 
		{if tagged "jamre" 
			{if tagged "js" 
				{if rand 0.0055 
					{tags add "js"}
					{delay 0.2
						{damage_report "body" "<c(ff0000)>."}
					}
				}
			}
		}
	} ;increase jam
}

;MAIN MENU END

;TERRAIN JAM INFLUENCE WHILE LYING BEGIN

{on "terrain_influence_1"
	{if "terrain_influence"
		{if lying 
			{if terrain_fx "snow" 
				{if rand 0.0055 
					{tags add "js"}
					{start_sound "human/move/snow"} 
					{damage_report "body" "<c(9e8af6)>snow jammed the gun"}
				}
			}
			{if terrain_fx "sand" 
				{if rand 0.0045 
					{tags add "js"} 
					{start_sound "human/move/sand"}
					{damage_report "body" "<c(e5c200)>sand fell into the ejection port"}
				}
			}
			{if terrain_fx "shallow_water" 
				{if rand 0.0025 
					{tags add "js"} 
					{start_sound "human/move/swim"}
					{damage_report "body" "<c(bdbdbd)>water fell into the ejection port"}
				}
			}
			{if terrain_fx "swamp" 
				{if rand 0.0045 
					{tags add "js"}
					{start_sound "human/move/swim"} 
					{damage_report "body" "<c(5d4e00)>water and dirt fell into the ejection port"}
				}
			}
			{if terrain_fx "mud" 
				{if rand 0.0045 
					{tags add "js"}
					{start_sound "human/move/snow"} 
					{damage_report "body" "<c(ff892a)>mud fell into the ejection port"}
				}
			}
		}	
	}
}

;TERRAIN JAM INFLUENCE WHILE LYING END

;LOGICAL CHECKS BEGIN

(define "tags_remove" ; so weapons switch their jamming data on weapon switch.
	{if tagged %iftag
		{tags remove %tagrem}
	}
)

{on "link_weapon"
	{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
		{with_effector
			{call "link_human"}
		}
	}
	{if stuff "pistol" ;pistol
		{tags add "pistolw"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;;
		{tags add "jammable"};;;;;;;;;;;JAMMABLE;;;;;;;;;;; 
		("tags_remove" 
			iftag("pistolw") 
				tagrem("smgw riflew sniperw shotgunw mgunw")
		) 
		{add_view "shell_smg" "shell" "fxshell"}
		{add_view "flash_gun_small" "flashbarrel" "foresight3"}
	else stuff "smg" ;smg
		{tags add "smgw"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;;
		{tags add "jammable"};;;;;;;;;;;JAMMABLE;;;;;;;;;;;
		("tags_remove" 
			iftag("smgw") 
				tagrem("pistolw mgunw riflew shotgunw sniperw")
		) 
		{add_view "flash_gun_small" "flashbarrel" "foresight3"}
		{add_view "shell_smg" "shell" "fxshell"}
	else stuff "rifle" ;rifle
		{tags add "riflew"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;;
		{tags add "jammable"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;; 
		("tags_remove" 
			iftag("riflew") 
				tagrem("pistolw mgunw smgw shotgunw sniperw")
		)
		{add_view "flash_gun_big" "flashbarrel" "foresight3"}
		{add_view "shell_mgun" "shell" "fxshell"}
	else stuff "ptr" ;rifle
		{tags add "ptrw"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;;
		("tags_remove" 
			iftag("ptrw") 
				tagrem("pistolw riflew jammable mgunw smgw shotgunw sniperw")
		) 
	else stuff "sniper" ;sniper
		{tags add "riflew"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;;
		{tags add "jammable"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;; 
		("tags_remove" 
			iftag("riflew") 
				tagrem("pistolw mgunw smgw shotgunw sniperw")
		) 
		{add_view "flash_gun_big" "flashbarrel" "foresight3"}
		{add_view "shell_mgun" "shell" "fxshell"}
	else stuff "shotgun" ;shotgun
		{tags add "shotgunw"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;;
		{tags add "jammable"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;;
			("tags_remove" 
				iftag("shotgunw") 
					tagrem("pistolw mgunw smgw riflew sniperw")
			) 
		{add_view "flash_shotgun" "flashbarrel" "foresight3"}
		{add_view "shell_shotgun" "shell" "foresight3"}

	else stuff "mgun" ;mgun
		{tags add "mgunw"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;;
		{tags add "jammable"} ;;;;;;;;;;;JAMMABLE;;;;;;;;;;;
		("tags_remove" 
			iftag("mgunw") 
				tagrem("pistolw smgw riflew sniperw shotgunw")) 
		{add_view "flash_gun_big" "flashbarrel" "foresight3"}
		{add_view "shell_mgun" "shell" "fxshell"}
	else stuff "flame_thrower"
		{tags add "mgunw"} 
		("tags_remove" 
			iftag("flamew") 
				tagrem("mgunw pistolw smgw riflew sniperw shotgunw")
		) ;;;;;;;;;;;NOTJAMMABLE;;;;;;;;;;;
		{add_view "flamer_fire" "flame" "foresight3"}
		{add_view "flamer_fire_barrel" "fire" "foresight3"}
		{view show "fire"}
		{view start "fire"}
	else
		{view hide "flashbarrel"}
		{view pause "flashbarrel"}
		{view pause "flame"}
	} 
}

;LOGICAL CHECKS END

;WEAPON JAM RATE PER CLASS BEGIN
	;set how often certain types of weapons will jam set_weapontype (0.0001)) ;.001% chance (0.0005)) ;.005% chance

{on "pistoljam"
	{if "gun_jamming_enabled" 
		{if bone "foresight3" 
			{if rand 0.0007 
				{tags add "js"} }}}} ; the tag js pulls the weapon into the jamming proccess.
{on "smgjam" 
	{if "gun_jamming_enabled" 
		{if bone "foresight3" 
			{if rand 0.0007 
				{tags add "js"} 
			}
		}
	}
}
{on "riflejam" 
	{if "gun_jamming_enabled" 
		{if bone "foresight3" 
			{if rand 0.0009 
				{tags add "js"} 
			}
		}
	}
}
{on "sniperjam" 
	{if "gun_jamming_enabled" 
		{if bone "foresight3" 
			{if rand 0.0009 
				{tags add "js"} 
			}
		}
	}
}
{on "shotgunjam"
	{if "gun_jamming_enabled" 
		{if bone "foresight3" 
			{if rand 0.001 
				{tags add "js"} 
			}
		}
	}
}
{on "mgunjam"
	{if "gun_jamming_enabled" 
		{if bone "foresight3" 
			{if rand 0.001 
				{tags add "js"} 
			}
		}
	}
}

;WEAPON JAM RATE PER CLASS EMD

;WEAPON JAM FIX LOGIC BEGIN

{on "manual_fix_timer" ;minimum 3.7 max:mugen(infinity) set_manualtimer ;MANUAL TIMER
	{if not "random_fix_timer" 
		{delay 15 
			{tags add "fixed"}
			{call "jam_fix"}
		}
	}
}

{on "jam_fix" ;FIXING THE JAM
	{if tagged "fixed"
		{if tagged "jam"
			{tags remove "jam"}
			{tags remove "fixed"}
			{call "spawn_shell"}
			{start_sound "weapon/reload"}
			{weapon_work "hand_right" 1}
			{if "cant_move"{chassis_work 1}} ;reenables the weapon
				{if not dead 
					{if able "select" 
						{if not senseless ;so the knocked out and dead wont be able to fix it they will restart
							{damage_report "body" "<c(00ff00)>jam fixed"}
						}
					}
				}
				{talk "jubilation"}
			{ani_stop "squat_reload_piat"}{ani_stop "lie_reload_piat"} 
			{if "cant_move"{chassis_work 1}}
			{if not dead 
				{if able "select" 
						{if not senseless 
						{if "ingame_jam_modifiers"
							{if rand 0.1 
								{attack_save}
								{damage_report "body" "<c(00ff00)>gun fixed: less jam"}
								{tags add "jamca"} ;jamca as in cautious
							else rand 0.1 
								{attack_load}
								{damage_report "body" "<c(dd0000)>gun damaged: increased jam"}
								{tags add "jamre"} ;jamre as in reckless, 
							else rand 0.05
								{attack_save}
								{damage_report "body" "<c(00ff00)>gun repaired: no more jamming at all"}
								{tags add "jamfi"} ;Jam Complete Fix
							}
						}
					}
				}
			}
		}
	}
}

;WEAPON JAM FIX LOGIC END

;WEAPON HANGFIRE LOGIC BEGIN
 
{on "hangfire"
	{tags add "hangfire"}
	{if rand 0.5 
		{weapon_work "hand_right" 0}
	} ;due to surplus ammo the gun will click but have a delay before firing, this could be potentially dangerous
	{if not tagged "jamre"
		{damage_report "body" "<c(dd0000)>hangfire"}
	}
	{if tagged "jamre"
		{damage_report "body" "<c(dd0000)>hangfire caused by damaged gun"}
	}
	{start_sound "gui/misc_gui_select"}
	{call "hangfire_chance"}
}

{on "hangfire_chance"
	{if rand 0.1 
		{delay 0.2 
			{tags add "hfixed"}
			{call "hangfire_pt2"}
		}
	else rand 0.1
		{delay 0.3 
			{tags add "hfixed"}
			{call "hangfire_pt2"}
		}
	else rand 0.1
		{delay 0.4 
			{tags add "hfixed"}
			{call "hangfire_pt2"}
		}
	else rand 0.1
		{delay 0.1 
			{tags add "hfixed"}
			{call "hangfire_pt2"}
		}
	else rand 0.1
		{delay 0.2 
			{tags add "hfixed"}
			{call "hangfire_pt2"}
		}
	else rand 0.1
		{delay 0.3 
			{tags add "hfixed"}
			{call "hangfire_pt2"}
		}
	else rand 0.1
		{delay 0.5 
			{tags add "hfixed"}
			{call "hangfire_pt2"}
		}
	else rand 0.1
		{delay 0.3 
			{tags add "hfixed"}
			{call "hangfire_pt2"}
		}
	else 
		{delay 0.4 
			{tags add "hfixed"}
			{call "hangfire_pt2"}
		}
	}
}

{on "hangfire_pt2"
	{if rand 0.2 
		("human_health" c(50))
	} ;hangfire damage to hands
	{delay 0.3 
	{talk "injuring"}}
	{if tagged "hfixed"
		{tags remove "hangfire"}
		{tags remove "hfixed"}
		{weapon_work "hand_right" 1}
		{call "hand_right"} 
	}
}

;WEAPON HANGFIRE LOGIC END

;WEAPON JAM CHECK BEGIN

{on fire "hand_right"
	{if tagged "jam" 
		{start_sound "gui/misc_gui_select"}} 
		{if tagged "jammable" ;only jammable weapons are to be jammed.
			{call "jam_enable"} ;checks whether gun jamming is enabled or not.
			{if "gun_jamming_enabled" 
				{call "gun_jam_mod_menu"} ;to configure jamming options
				{if tagged "smgw" 
					{call "smgjam"}
				}
				{if tagged "riflew" 
					{call "riflejam"}
				}
				{if tagged "pistolw" 
					{call "pistoljam"}
				} 
				{if tagged "mgunw" 
					{call "mgunjam"}
				} 
				{if tagged "shotgunw" 
					{call "shotgunjam"}
				}
				{call "terrain_influence_1"} ;to check the other jam values
				{call "jam_modifiers_menu"} ;to check the other jam values
				{if "hangfire"
					{if not tagged "jamre"
						{if rand 0.0002 
							{call"hangfire"}}} ;HANGFIRE 0.0002 chance
					{if tagged "jamre"{if rand 0.0021 {call"hangfire"}}} ;damaged gun
				}
			}
		{if not tagged "hangfire"
		{if not tagged "jamfi" 
			{if not tagged "fixed" 
				{if tagged "js" 
					{tags remove "js"} ;so the weapon can be jammed again some time later if not tagged jamfi
					{weapon_work "hand_right" 0} ;stops the weapon from firing
					{if "cant_move"
						{chassis_work 0}
					} ;stops the soldier from moving while fixing the jam
					{tags add "jam"} 
					{delay 0.3 
						{if able "select" 
							{if rand 0.5 
								{start_sound "gui/misc_gui_select"}
							}
						}
					} ;Put able select so the dead won't try to fix their pb and jam in the morning, ahem I meant weapon jam.
					{delay 0.6 
						{if able "select" 
							{if rand 0.5 
								{start_sound "gui/misc_gui_select"}
							}
						}
					} ;also the sound is the soldier trying to pull the trigger and failing to shoot. For AS1 and 2, for mow you'll have to make your own trigger sound.
					{delay 0.8 
						{if able "select" 
							{if rand 0.5 
								{start_sound "gui/misc_gui_select"}
							}
						}
					} ;the soldier repeats pulling the trigger, thinking he/she may have a fatigued finger, giving as much force the next time.
					{delay 1.4 
						{if able "select" 
							{if rand 0.5 
								{start_sound "gui/misc_gui_select"}
							}
						}
					}
					{delay 1.6 
						{damage_report "body" "<c(9e8af6)>jammed"}
						{delay 5 1 
							{if tagged "jamca" 
								{if rand 0.1 
									{damage_report "body" "<c(9e8af6)>it still jammed!?"}
								} 
							{tags remove "jamca"}
							}
							{if tagged "jamre" 
								{if rand 0.1 
									{damage_report "body" "<c(9e8af6)>jammed again huh"}
								} 
							{tags remove "jamre"}
							}
						}
					}
					{delay 2.0 
						{talk "injuring"}} ;Jimmies have been rustled.
							{delay 2.1 
								{if able "select" 
									{if rand 0.8 
										{start_sound "gui/misc_gui_select"}
									}
								}
							}
							{delay 2.2 
								{if able "select" 
									{if rand 0.7 
										{start_sound "gui/misc_gui_select"}
									}
								}
							}
							{delay 2.3 
								{if able "select" 
									{if rand 0.6 
										{start_sound "gui/misc_gui_select"}
									}
								}
							}
							{delay 2.4 
								{if able "select" 
									{if rand 1.0 
										{if tagged "winterjam" 
											{damage_report "body" "<c(9eccff)>by the winter"}
											{talk "injuring"}
											{if "winter_sound" 
												{start_sound "world/winter/04"}
												{tags remove "winterjam"}
											}
										}
									}
								}
							}
							{delay 3.4 
								{if able "select" 
									{if rand 0.5 
										{start_sound "gui/misc_gui_select"}
										{delay 3.5 
											{talk "things_look_blue"}
										}
									}
								}
							}
							{delay 3.5 
								{if "jam_fix_animations"
									{if able "select" 
										{tags add "jam"} 
										{if rand 0.7 
											{ani_play "squat_reload_piat" 1.0 loop} 
										else {ani_play "lie_reload_piat" 1.0 loop}
										}
									}
								}
							} ;animations of fixing the weapon}
							
							;Fixing the Jam ;get rid of the shell that jammed your weapon, the immersion is real.
							
							{delay 3.6 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 3.51 
								{if tagged "jam"
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										}
									}
								} 
							}
							{delay 3.61 
								{if tagged "jam"
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										}
									}
								}
							} 
							{delay 3.7 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 3.71
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										}
									}
								}
							} 
							{delay 3.8 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 3.81
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										}
									}
								} 
							} 
							{delay 4.4 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 4.41
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										} 
									}
								} 
							} 
							{delay 5.3 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 5.31
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										}
									}
								} 
							} 
							{delay 6.6 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 6.61
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										}
									}
								} 
							} 
							{delay 7.8 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 7.81
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										} 
									}
								} 
							} 
							{delay 8.4 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 8.41
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										} 
									}
								} 
							} 
							{delay 9.3 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 9.31
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										}
									}
								} 
							} 
							{delay 10.6 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 10.61
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										} 
									}
								} 
							} 
							{delay 11.8 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 11.81
								{if tagged "jam" 
									{if not able "select" 
									{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										} 
									}
								} 
							} 
							{delay 12.4 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 12.41
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										} 
									}
								} 
							} 
							{delay 13.4 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 13.41
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										} 
									}
								} 
							} 
							{delay 14.4 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 14.41
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										} 
									}
								} 
							} 
							{delay 15.4 
								{if able "select" 
									{if rand 0.3 
										{if tagged "jam" 
											{start_sound "weapon/reload"}
										}
									}
								}
							}
							{delay 15.41
								{if tagged "jam" 
									{if not able "select" 
										{tags remove "jam"}
										{throw_on_ground}
										{delay 0.01 
											{ani_stop "squat_reload_piat"}
											{delay 0.012
												{ani_stop "lie_reload_piat"}
											}
										}
									}
								} 
							} 
							{if "random_fix_timer" ;Random Jam fix timers
								{if rand 0.1 
									{delay 15 
										{tags add "fixed"}
										{call "jam_fix"}
									}
									else rand 0.2
										{delay 6 
											{tags add "fixed"}
											{call "jam_fix"}
										}
									else rand 0.3
										{delay 7 
											{tags add "fixed"}
											{call "jam_fix"}
										}
									else rand 0.4
										{delay 8 
											{tags add "fixed"}
											{call "jam_fix"}
										}
									else rand 0.5
										{delay 9 
											{tags add "fixed"}
											{call "jam_fix"}
										}
									else rand 0.6
										{delay 10 
											{tags add "fixed"}
											{call "jam_fix"}
										}
									else rand 0.3
										{delay 3.7 
											{tags add "fixed"}
											{call "jam_fix"}
										}
									else rand 0.2
										{delay 4 
											{tags add "fixed"}
											{call "jam_fix"}
										}
									else 
										{delay 15 
											{tags add "fixed"}
											{call "jam_fix"}
										}
									}
							else
								{call "manual_fix_timer"} ;Manually set timer (go to menu to change)
							}
						}
					} 
				} 
			}
		}
		
;WEAPON JAM CHECK END
		
;WEAPON JAM CHECK BEGIN		
	{view show "flashbarrel"}
	{view start "flashbarrel"}
	{view start "shell"} 
	{view start "flame"}
	{kill_delay "fire"}
	{delay 0.1 "shell" 
		{view pause "shell"}
	} 
	{delay 0.1 "fire"
		{view hide "flashbarrel"}
		{view pause "flashbarrel"}
	}
	{delay 0.5 "fire"
		{view pause "flame"}
	}		
	{spawn "bazooka_shot" "fxshot" x}
	{if not tagged "ptrw" 
		{if bone "foresight3" 
			{if not tagged "jam"
				{if tagged "smgw"
				{call "spawn_shell"}
				} 
				{if tagged "mgunw"
					{call "spawn_shell"}
				} 
				{if tagged "riflew"
					{call "spawn_shell"}
				} 
				{if tagged "pistolw"
					{call "spawn_shell"}
				} 
				{if tagged "sniperw"
					{call "spawn_shell"}
				} 
				{if tagged "shotgunw"
					{call "spawn_shell"}
				}
			}
		}
	} 
}