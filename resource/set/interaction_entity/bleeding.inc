{on "internal_bleeding_process"
	{if not dead
		{if tagged "internal_bleeding"
			{delay 10
				("human_health" c(10))
				{call "internal_bleeding_process"}
				{if not tagged "major_artery_bleeding"
					{if not tagged "moderate_artery_bleeding"
						{if not tagged "major_vein_bleeding"
							{if not tagged "moderate_vein_bleeding"
								{damage_report "body" "<c(dd0000)>Internal Bleeding"}
								{talk "injuring"}
							}
						}
					}
				}
			}
		}
	}
}

{on "major_artery_bleeding_process"
	{if user_control
		{if not linked "vehicle"
			{delay 10
				{if not dead
					{if tagged "major_artery_bleeding"
						("human_health" c(30))
						{damage_report "body" "<c(dd0000)>Major Arterial Bleeding"}
						{talk "injuring"}
						{spawn "bloodstain" "basis" x}
						{call "major_artery_bleeding_process"}
						{call "stop-heal-fast"}
					}
				}
			}
		else
			{tags remove "major_artery_bleeding"}
		}
	else
		{tags remove "major_artery_bleeding"}
	}
}

{on "moderate_artery_bleeding_process"
	{if user_control
		{if not linked "vehicle"
			{delay 10
				{if not dead
					{if tagged "moderate_artery_bleeding"
						{if not tagged "major_artery_bleeding"
							{if not tagged "major_vein_bleeding"
								{damage_report "body" "<c(dd0000)>Moderate Arterial Bleeding"}
								{talk "injuring"}
							}
						}
						("human_health" c(10))
						{call "moderate_artery_bleeding_process"}
						{call "stop-heal-fast"}
					}
				}
			}
		else
			{tags remove "moderate_artery_bleeding"}
		}
	else
		{tags remove "moderate_artery_bleeding"}
	}
}

{on "major_vein_bleeding_process"
	{if user_control
		{if not linked "vehicle"
			{delay 10
				{if not dead
					{if tagged "major_vein_bleeding"
						{if not tagged "major_artery_bleeding"
							{damage_report "body" "<c(dd0000)>Major Venous Bleeding"}
							{talk "injuring"}
							{spawn "bloodstain" "basis" x}
						}
						("human_health" c(15))
						{call "major_vein_bleeding_process"}
						{call "stop-heal-fast"}
					}
				}
			}
		else
			{tags remove "major_vein_bleeding"}
		}
	else
		{tags remove "major_vein_bleeding"}
	}
}

{on "moderate_vein_bleeding_process"
	{if user_control
		{if not linked "vehicle"
			{delay 10
				{if not dead
					{if tagged "moderate_vein_bleeding"
						{if not tagged "major_artery_bleeding"
							{if not tagged "moderate_artery_bleeding"
								{if not tagged "major_vein_bleeding"
									{damage_report "body" "<c(dd0000)>Moderate Venous Bleeding"}
									{talk "injuring"}
								}
							}
						}
						("human_health" c(5))
						{call "moderate_vein_bleeding_process"}
						{call "stop-heal-fast"}
					}
				}
			}
		else
			{tags remove "moderate_vein_bleeding"}
		}
	else
		{tags remove "moderate_vein_bleeding"}
	}
}