{on "bleeding" sync
	{if user_control
		{if not linked "vehicle"
		{delay 7
				{if not dead
					{if tagged "human_bleeding"
						("human_health" c(5))
						{damage_report "body" "<c(dd0000)>Bleeding"}
						{talk "injuring"}
						{call "bleeding"}
					}
				}
			}
		else
			{tags remove "human_bleeding"}
		}
	else
		{tags remove "human_bleeding"}
	}
}