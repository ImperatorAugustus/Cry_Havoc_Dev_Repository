(define "rand_damage"
	{if rand 0.2 {health_damage_count %0 {effects "" "hit" "damage" "die" "die"}}
		else rand 0.2 {health_damage_count %1 {effects "" "hit" "damage" "die" "die"}}
		else rand 0.2 {health_damage_count %2 {effects "" "hit" "damage" "die" "die"}}
		else rand 0.2 {health_damage_count %3 {effects "" "hit" "damage" "die" "die"}}
		else {health_damage_count %4 {effects "" "hit" "damage" "die" "die"}}
		}
)
(define "rand_damage2"
	{if rand 0.1 ("health_damage_rand" c(%dmg) offset(0.75) )
		else rand 0.1 ("health_damage_rand" c(%dmg) offset(0.80) )
		else rand 0.1 ("health_damage_rand" c(%dmg) offset(0.85) )
		else rand 0.1 ("health_damage_rand" c(%dmg) offset(0.90) )
		else rand 0.1 ("health_damage_rand" c(%dmg) offset(0.95) )
		else rand 0.1 ("health_damage_rand" c(%dmg) offset(1.00) )
		else rand 0.1 ("health_damage_rand" c(%dmg) offset(1.05) )
		else rand 0.1 ("health_damage_rand" c(%dmg) offset(1.10) )
		else rand 0.1 ("health_damage_rand" c(%dmg) offset(1.20) )
		else ("health_damage_rand" c(%dmg) offset(1.25) )
		}
)

{if volume "head"
			{if not dead
				{if volume_armored
					;{play_sound "hit/small/metal"}
					;{spawn "metal_hit_bul"}
					{if stuff "7-62_pistol" {if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					else stuff "8_pistol" {if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					else stuff "9_pistol" {if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					else stuff "45_pistol" {if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					else stuff "30_carbine" {if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					else stuff "7-92_kurz" {if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					else stuff "6-5_rifle" {if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					else stuff "7-62_rifle" {if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					else stuff "7-7_rifle" {if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					else stuff "7-92_rifle" {if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					else 					{if rand 0.95 
												("human_health" c(350))
											else
												("human_health" c(10))
											}
					}
				else
										{if rand 0.95 
											("human_health" c(350))
										else
											("human_health" c(10))
										}
				}
			}
		else volume "face"
			("human_health" c(350))
		}
		{if volume "body"
			{if not dead
				{if stuff "7-62_pistol"
					{if rand 0.95
						("rand_damage" args 50 60 70 75 90)
							{if not dead
								{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "8_pistol"
					{if rand 0.95
						("rand_damage" args 45 55 65 70 85)
							{if not dead
								{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "9_pistol"
					{if rand 0.95
						("rand_damage" args 50 60 70 75 90)
							{if not dead
									{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "45_pistol"
					{if rand 0.90
						("rand_damage" args 50 60 70 80 90)
							{if not dead
									{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "30_carbine"
					{spawn "blood_hit"}
					{if rand 0.95 
						("rand_damage" args 50 60 70 80 90)
							{if not dead
									{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "7-92_kurz" ;1.9k J ;german 7.92 kurz ; stg44
					{spawn "blood_hit"}
					{if rand 0.80
						("rand_damage" args 60 70 80 130 180)
							{if not dead
									{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "6-5_rifle"
					{spawn "blood_hit"}
					{if rand 0.80
						("rand_damage" args 60 70 80 130 180)
							{if not dead
									{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "7-62_rifle" ;3.6-3.7k J ;soviet and US 7.62
					{spawn "blood_hit"}  
					{if rand 0.80
						("rand_damage" args 75 100 125 150 200)
							{if not dead
									{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "7-7_rifle" ;3.1-3.2k J ;british .303
					{spawn "blood_hit"}  
					{if rand 0.80 
						("rand_damage" args 70 95 120 145 195)
							{if not dead
									{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "7-92_rifle" ;3.7k J ;german 7.92 mauser
					{spawn "blood_hit"}  
					{if rand 0.80
						("rand_damage" args 75 100 125 150 200)
							{if not dead
									{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "rifle_fg"
					{spawn "blood_hit"}
					{if rand 0.7
						("rand_damage" args 140 150 200 225 250)
							{if not dead
									{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
				{if stuff "hmgun"
					{spawn "blood_hit"}
					{if rand 0.7
						("rand_damage" args 100 125 150 175 200)
							{if not dead
									{tags add "human_bleeding"}{call "bleeding"}
							}
					else
						("human_health" c(350))
					}
				}
			}
		}
		
		{if volume "foot1l"
			{if not dead
				{if stuff "7-62_pistol" 
					{if rand 0.3 ("rand_damage2" dmg(40)) 	
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "8_pistol"    
					{if rand 0.3 ("rand_damage2" dmg(40))
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "9_pistol"    
					{if rand 0.3 ("rand_damage2" dmg(40))	
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "45_pistol"   
					{if rand 0.4 ("rand_damage2" dmg(50))	
						{if not dead
							{if rand 0.04
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "30_carbine"  
					{if rand 0.4 ("rand_damage2" dmg(50))
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-92_kurz"  	
					{if rand 0.4 ("rand_damage2" dmg(60))
						{if not dead
							{if rand 0.07
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "6-5_rifle"  	
					{if rand 0.5 ("rand_damage2" dmg(50))
						{if not dead
							{if rand 0.07
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-62_rifle"  
					{if rand 0.5 ("rand_damage2" dmg(75))	
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-7_rifle"  	
					{if rand 0.5 ("rand_damage2" dmg(75))
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					}
				}
				{if stuff "7-92_rifle"  
					{if rand 0.5 ("rand_damage2" dmg(75))
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "hmgun"  		
					{if rand 0.7 ("rand_damage2" dmg(100))
						{if not dead
							{if rand 0.15
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					}
				}
			}
		}
		
		{if volume "foot1r"
			{if not dead
				{if stuff "7-62_pistol" 
					{if rand 0.3 ("rand_damage2" dmg(40)) 	
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "8_pistol"    
					{if rand 0.3 ("rand_damage2" dmg(40))
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "9_pistol"    
					{if rand 0.3 ("rand_damage2" dmg(40))	
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "45_pistol"   
					{if rand 0.4 ("rand_damage2" dmg(50))	
						{if not dead
							{if rand 0.04
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "30_carbine"  
					{if rand 0.4 ("rand_damage2" dmg(50))
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-92_kurz"  	
					{if rand 0.4 ("rand_damage2" dmg(60))
						{if not dead
							{if rand 0.07
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "6-5_rifle"  	
					{if rand 0.5 ("rand_damage2" dmg(50))
						{if not dead
							{if rand 0.07
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-62_rifle"  
					{if rand 0.5 ("rand_damage2" dmg(75))	
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-7_rifle"  	
					{if rand 0.5 ("rand_damage2" dmg(75))
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					}
				}
				{if stuff "7-92_rifle"  
					{if rand 0.5 ("rand_damage2" dmg(75))
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "hmgun"  		
					{if rand 0.7 ("rand_damage2" dmg(100))
						{if not dead
							{if rand 0.15
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					}
				}
			}
		}
		
		{if volume "arm1l"
		{if not dead
				{if stuff "7-62_pistol" 
					{if rand 0.3 ("rand_damage2" dmg(25)) 	
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "8_pistol"    
					{if rand 0.3 ("rand_damage2" dmg(25))
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "9_pistol"    
					{if rand 0.3 ("rand_damage2" dmg(25))	
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "45_pistol"   
					{if rand 0.4 ("rand_damage2" dmg(35))	
						{if not dead
							{if rand 0.04
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "30_carbine"  
					{if rand 0.4 ("rand_damage2" dmg(35))
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-92_kurz"  	
					{if rand 0.4 ("rand_damage2" dmg(45))
						{if not dead
							{if rand 0.07
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "6-5_rifle"  	
					{if rand 0.5 ("rand_damage2" dmg(35))
						{if not dead
							{if rand 0.07
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-62_rifle"  
					{if rand 0.5 ("rand_damage2" dmg(50))	
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-7_rifle"  	
					{if rand 0.5 ("rand_damage2" dmg(50))
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					}
				}
				{if stuff "7-92_rifle"  
					{if rand 0.5 ("rand_damage2" dmg(50))
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "hmgun"  		
					{if rand 0.7 ("rand_damage2" dmg(100))
						{if not dead
							{if rand 0.15
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					}
				}
			}
		}
		{if volume "arm1l"
		{if not dead
				{if stuff "7-62_pistol" 
					{if rand 0.3 ("rand_damage2" dmg(25)) 	
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "8_pistol"    
					{if rand 0.3 ("rand_damage2" dmg(25))
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "9_pistol"    
					{if rand 0.3 ("rand_damage2" dmg(25))	
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "45_pistol"   
					{if rand 0.4 ("rand_damage2" dmg(35))	
						{if not dead
							{if rand 0.04
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "30_carbine"  
					{if rand 0.4 ("rand_damage2" dmg(35))
						{if not dead
							{if rand 0.03
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-92_kurz"  	
					{if rand 0.4 ("rand_damage2" dmg(45))
						{if not dead
							{if rand 0.07
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "6-5_rifle"  	
					{if rand 0.5 ("rand_damage2" dmg(35))
						{if not dead
							{if rand 0.07
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-62_rifle"  
					{if rand 0.5 ("rand_damage2" dmg(50))	
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "7-7_rifle"  	
					{if rand 0.5 ("rand_damage2" dmg(50))
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					}
				}
				{if stuff "7-92_rifle"  
					{if rand 0.5 ("rand_damage2" dmg(50))
						{if not dead
							{if rand 0.1
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					} 
				}
				{if stuff "hmgun"  		
					{if rand 0.7 ("rand_damage2" dmg(100))
						{if not dead
							{if rand 0.15
								{tags add "human_bleeding"}{call "bleeding"}
							}
						}
					}
				}
			}
		}