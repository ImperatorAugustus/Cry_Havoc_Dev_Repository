;MAIN MENU BEGIN

{on "jam_settings" ;jam settings

	{set "gun_jamming_enabled" 1} ;Disable/Enable Gun Jamming.
	
	;Animations

	{set "cant_move" 1} ;stops the unit from moving to prevent the animation from conflicting with the movement when set to "1".
	{set "jam_fix_animations" 0} ;units get a reloading animation when trying to fix the weapon jam.

	;Random/Enviroment Jam Modifiers
	
	{set "repeat_jam_chance_randomizer" 1} ;randomly gives decreased or increased proabability of jamming after it is fixed.
	
	{if "winter" ;these are not fully set up currently, requires mission editing
		{if rand 0.0065 
			{tags add "winter_jam"} 
		}
	}
	
	{if "harsh_winter"
		{if rand 0.0155 
			{tags add "harsh_winter_jam"}
		}
	}

	{if "sand_storm"
		{if rand 0.0155 
			{tags add "sandstorm_jam"}
		}
	}
	
	;Terrain Influence

	{set "terrain_influence" 1} ;when soldiers are LYING DOWN, on snow or swamps,sand,mud, and shallow water they will be more at risk of jamming until they squat or stand up.

	{set "random_fix_timer" 1} ;Random jam fix timers disable to set to manual timer search for set_manualtimer

	;HangFire
	
	{set "hangfire" 1} ;randomly forces a delay to gunfire, could be potentially dangerous, as the surplus ammo could damage the barrel doing damage to the soldier's hands.
}
 
{on "jam_modifiers_menu" 
	{if "repeat_jam_chance_randomizer" 
		{if tagged "jam_cautious" 
			{if tagged "call_for_jamming" 
				{if rand 0.7 
					{tags remove "call_for_jamming"}
					{tags remove "winter_jam"}
					{delay 0.2
						{damage_report "body" "<c(FFA500)>."}
					}
				}
			}
		}
	} ;decrease jam
	{if "repeat_jam_chance_randomizer" 
		{if tagged "jam_reckless" 
			{if tagged "call_for_jamming" 
				{if rand 0.0055 
					{tags add "call_for_jamming"}
					{delay 0.2
						{damage_report "body" "<c(FFA500)>."}
					}
				}
			}
		}
	} ;increase jam
}

;MAIN MENU END

;TERRAIN JAM INFLUENCE BEGIN

{on "terrain_influence_check"
	{if "terrain_influence"
		{if lying 
			{if terrain_fx "shallow_water" 
				{if rand 0.0025 
					{tags add "call_for_jamming"} 
					{start_sound "human/move/lying/shallow_water"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Water Interupts Cycle"}
				}
			}
			{if terrain_fx "water" 
				{if rand 0.01 
					{tags add "call_for_jamming"} 
					{start_sound "swim"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Water Interupts Cycle"}
				}
			}
			{if terrain_fx "puddle" 
				{if rand 0.0035 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/puddle"}
					{start_sound "gear_rattle_normal"}					
					{damage_report "body" "<c(FFA500)>Water and Mud Interupts Cycle"}
				}
			}
			{if terrain_fx "swamp" 
				{if rand 0.0045 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/shallow_water"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Water and Muck Interupts Cycle"}
				}
			}
			
			{if terrain_fx "snow" 
				{if rand 0.0035 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/snow"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Snow Interupts Cycle"}
				}
			}
			{if terrain_fx "ice" 
				{if rand 0.0025 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/ice"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Snow Interupts Cycle"}
				}
			}
			{if terrain_fx "bridge_snow" 
				{if rand 0.0035 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/snow"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Snow Interupts Cycle"}
				}
			}
			
			{if terrain_fx "sand" 
				{if rand 0.0045 
					{tags add "call_for_jamming"} 
					{start_sound "human/move/lying/ground"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Sand Interupts Cycle"}
				}
			}
			{if terrain_fx "rock" 
				{if rand 0.0030 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/ground"}
					{start_sound "gear_rattle_normal"} 
					{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
				}
			}
			{if terrain_fx "ground" 
				{if rand 0.0030 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/ground"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
				}
			}
			{if terrain_fx "mud" 
				{if rand 0.0045 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/mud"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Mud Interupts Cycle"}
				}
			}
			{if terrain_fx "grass" 
				{if rand 0.0035 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/grass"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
				}
			}
			
			{if terrain_fx "bridge" 
				{if rand 0.0030 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/road"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
				}
			}
			{if terrain_fx "bridge_wood" 
				{if rand 0.0030 
					{start_sound "human/move/lying/road"}
					{start_sound "gear_rattle_normal"}
					{start_sound "human/move/snow"} 
					{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
				}
			}
			{if terrain_fx "bridge_steel" 
				{if rand 0.0030 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/metal"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
				}
			}
			
			{if terrain_fx "road" 
				{if rand 0.0030 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/road"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
				}
			}
			{if terrain_fx "country_road" 
				{if rand 0.0035 
					{tags add "call_for_jamming"}
					{start_sound "human/move/lying/ground"}
					{start_sound "gear_rattle_normal"}
					{damage_report "body" "<c(FFA500)>Dirt Interupts Cycle"}
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
		{tags add "has_pistol"} 
		{tags add "jammable"} 
		("tags_remove" iftag("has_pistol") tagrem("has_smg has_rifle has_sniper has_shotgun has_mgun")) 
	else stuff "smg" ;smg
		{tags add "has_smg"} 
		{tags add "jammable"}
		("tags_remove" 	iftag("has_smg") tagrem("has_pistol has_mgun has_rifle has_shotgun has_sniper")) 
	else stuff "rifle" ;rifle
		{tags add "has_rifle"} 
		{tags add "jammable"}  
		("tags_remove" iftag("has_rifle") tagrem("has_pistol has_mgun has_smg has_shotgun has_sniper"))
	else stuff "ptr" ;anti tank rifle
		{tags add "has_ptr"} 
		("tags_remove" iftag("has_ptr") tagrem("has_pistol has_rifle jammable has_mgun has_smg has_shotgun has_sniper")) 
	else stuff "sniper" ;sniper
		{tags add "has_rifle"} 
		{tags add "jammable"}  
		("tags_remove" iftag("has_rifle") tagrem("has_pistol has_mgun has_smg has_shotgun has_sniper")) 
	else stuff "shotgun" ;shotgun
		{tags add "has_shotgun"} 
		{tags add "jammable"} 
		("tags_remove" iftag("has_shotgun") tagrem("has_pistol has_mgun has_smg has_rifle has_sniper")) 
	else stuff "mgun" ;mgun
		{tags add "has_mgun"} 
		{tags add "jammable"} 
		("tags_remove" iftag("has_mgun") tagrem("has_pistol has_smg has_rifle has_sniper has_shotgun")) 
	else stuff "flame_thrower"
		{tags add "has_mgun"} 
		("tags_remove" iftag("has_flamethrower") tagrem("has_mgun has_pistol has_smg has_rifle has_sniper has_shotgun")) ;;;;;;;;;;;NOTJAMMABLE;;;;;;;;;;;
	else
	} 
}

;LOGICAL CHECKS END

;WEAPON JAM RATE PER CLASS BEGIN
	;set how often certain types of weapons will jam set_weapontype 0.0001 ;.001% chance 0.0005 ;.005% chance

{on "pistol_jam"
	{if "gun_jamming_enabled" 
		{if bone "foresight3" 
			{if rand 0.001 
				{tags add "call_for_jamming"} 
			}
		}
	}
} ; the tag js pulls the weapon into the jamming proccess.
{on "smg_jam" 
	{if "gun_jamming_enabled" 
		{if bone "Foresight11" 
			{if rand 0.001 
				{tags add "call_for_jamming"} 
			}
		}
	}
}
{on "rifle_jam" 
	{if "gun_jamming_enabled" 
		{if bone "foresight12" 
			{if rand 0.0007 
				{tags add "call_for_jamming"} 
			}
		}
	}
}
{on "sniper_jam" 
	{if "gun_jamming_enabled" 
		{if bone "foresight12" 
			{if rand 0.0005 
				{tags add "call_for_jamming"} 
			}
		}
	}
}
{on "shotgun_jam" ; not used
	{if "gun_jamming_enabled" 
		{if bone "foresight12" 
			{if rand 0.001 
				{tags add "call_for_jamming"} 
			}
		}
	}
}
{on "mgun_jam"
	{if "gun_jamming_enabled" 
		{if bone "foresight14" 
			{if rand 0.001 
				{tags add "call_for_jamming"} 
			}
		}
	}
}

;WEAPON JAM RATE PER CLASS EMD

;WEAPON JAM FIX LOGIC BEGIN

{on "manual_fix_timer" ;minimum 3.7 ;MANUAL TIMER
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
			{if "cant_move"
				{chassis_work 0}
			} ;reenables the weapon
			{if not dead 
				{if able "select" 
					{if not senseless ;so the knocked out and dead wont be able to fix it they will restart
						{damage_report "body" "<c(FFA500)>Jam Fixed"}
					}
				}
			}
			{talk "jubilation"}
			{ani_stop "squat_reload_bazooka"}
			{ani_stop "lie_reload_bazooka"} 
			{if "cant_move"
				{chassis_work 1}
			}
			{if not dead 
				{if able "select" 
						{if not senseless 
						{if "repeat_jam_chance_randomizer"
							{if rand 0.1 
								{attack_save}
								{damage_report "body" "<c(FFA500)>Gun Fixed: Less Jam"}
								{tags add "jam_cautious"} 
							else rand 0.1 
								{attack_load}
								{damage_report "body" "<c(FFA500)>Gun Damaged: Increased Jam"}
								{tags add "jam_reckless"} 
							else rand 0.05
								{attack_save}
								{damage_report "body" "<c(FFA500)>Gun Repaired: Minimal Jamming For Now"}
								{tags add "jam_fixed"} 
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
	{weapon_work "hand_right" 0} ;due to surplus ammo the gun will click but have a delay before firing, this could be potentially dangerous
	{if not tagged "jam_reckless"
		{damage_report "body" "<c(FFA500)>Hangfire"}
	}
	{if tagged "jam_reckless"
		{damage_report "body" "<c(FFA500)>Hangfire From Damaged Gun"}
	}
	{if rand 0.1 
		{delay 0.2
			{weapon_work "hand_right" 1}
			{tags remove "hangfire"}
		}
	else rand 0.1
		{delay 0.4 
			{weapon_work "hand_right" 1}
			{tags remove "hangfire"}
		}
	else rand 0.1
		{delay 0.5 
			{weapon_work "hand_right" 1}
			{tags remove "hangfire"}
		}
	else rand 0.1
		{delay 0.6 
			{weapon_work "hand_right" 1}
			{tags remove "hangfire"}
		}
	else rand 0.1
		{delay 1 
			{weapon_work "hand_right" 1}
			{tags remove "hangfire"}
		}
	else rand 0.1
		{delay 1.2 
			{weapon_work "hand_right" 1}
			{tags remove "hangfire"}
		}
	else rand 0.1
		{delay 1.3 
			{weapon_work "hand_right" 1}
			{tags remove "hangfire"}
		}
	else rand 0.1
		{delay 1.4 
			{weapon_work "hand_right" 1}
			{tags remove "hangfire"}
		}
	else rand 0.1
		{delay 1.5 
			{weapon_work "hand_right" 1}
			{tags remove "hangfire"}
		}
	else
		{delay 1.5 
			{call "squib"}
		}
	}
}

{on "squib"
	{damage_report "body" "<c(FFA500)>Squib Deflagrate: 50 Damage"}
	{view start "grenade_debris"}
	("human_health" c(50)) ;hangfire damage to hands
	{delay 0.3 
		{talk "injuring"}
	}
	{delay 5 
		{weapon_work "hand_right" 1}
		{tags remove "hangfire"}
		{damage_report "body" "<c(FFA500)>Squib Damages Gun: Partial Repair"}
		{tags add "jam_reckless"} ;needs updated to severe or gun destruction
	}
}

;WEAPON HANGFIRE LOGIC END

;WEAPON JAM CHECK BEGIN

{on fire "hand_right"
	{if effector "stuff weapon"		;// see interaction_entity/stuff.inc
			{with_effector
				{call "fire"}
			}
	}
	{if tagged "jammable" ;only jammable weapons are to be jammed.
		{call "jam_settings"} ;checks whether gun jamming is enabled or not.
		{if "gun_jamming_enabled" 
			{if tagged "has_smg" 
				{call "smg_jam"}
			}
			{if tagged "has_rifle" 
				{call "rifle_jam"}
			}
			{if tagged "has_pistol" 
				{call "pistol_jam"}
			} 
			{if tagged "has_mgun" 
				{call "mgun_jam"}
			} 
			{if tagged "has_shotgun" 
				{call "shotgun_jam"}
			}
			{call "terrain_influence_check"} ;to check the other jam values
			{call "jam_modifiers_menu"} ;to check the other jam values
			{if "hangfire"
				{if not tagged "jam_reckless"
					{if rand 0.0002 
						{call "hangfire"}
					}
				} ;HANGFIRE 0.0002 chance
				{if tagged "jam_reckless"
					{if rand 0.0021 
						{call "hangfire"}
					}
				} ;damaged gun
			}
		}
		{if not tagged "hangfire"
			{if not tagged "jam_fixed" 
				{if not tagged "fixed" 
					{if tagged "call_for_jamming" 
						{tags remove "call_for_jamming"} ;so the weapon can be jammed again some time later if not tagged "jam_fixed"
						{weapon_work "hand_right" 0} ;stops the weapon from firing
						{if "cant_move"
							{chassis_work 0}
						} ;stops the soldier from moving while fixing the jam
						{tags add "jam"} 
						{delay 1.6 
							{damage_report "body" "<c(FFA500)>Jammed"}
							{delay 5 
								{if tagged "jam_cautious" 
									{if rand 0.1 
										{damage_report "body" "<c(FFA500)>it still jammed!?"}
									} 
									{tags remove "jam_cautious"}
								}
								{if tagged "jam_reckless" 
									{if rand 0.1 
										{damage_report "body" "<c(FFA500)>Jammed again huh"}
									} 
								{tags remove "jam_reckless"}
								}
							}
						}
						{delay 2.0 
							{talk "injuring"}
						} 
						{delay 2.4 
							{if able "select" 
								{if rand 1.0 
									{if tagged "winter_jam" 
										{damage_report "body" "<c(9eccff)>by the winter"}
										{talk "injuring"}
										{if "winter_sound" 
											{start_sound "world/winter/04"}
											{tags remove "winter_jam"}
										}
									}
								}
							}
						}
						{delay 3.5 
							{if "jam_fix_animations"
								{if able "select" 
									{tags add "jam"} 
									{if rand 0.7 
										{ani_play "squat_reload_bazooka" 1.0 loop} 
									else {ani_play "lie_reload_bazooka" 1.0 loop}
									}
								}
							}
						} ;animations of fixing the weapon
							
						;Fixing the Jam ;get rid of the shell that jammed your weapon.
							
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
										{ani_stop "squat_reload_bazooka"}
										{delay 0.012
											{ani_stop "lie_reload_bazooka"}
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
							{call "manual_fix_timer"} ;Manually set timer
						}
					}
				} 
			} 
		}
	}
}
		
;WEAPON JAM CHECK END