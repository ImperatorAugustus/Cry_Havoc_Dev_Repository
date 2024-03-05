{on "internal_bleeding_process"
	{if not dead
		{if tagged "internal_bleeding"
			("human_health" c(10))
			{damage_report "body" "<c(dd0000)>Internal Bleeding"}
			{talk "injuring"}
			{call_synced "internal_bleeding_process"}
		}
	}

}

{on "major_artery_bleeding_process"
	{if user_control
		{if not linked "vehicle"
			{delay 5
				{if not dead
					{if tagged "major_artery_bleeding"
						("human_health" c(30))
						{damage_report "body" "<c(dd0000)>Major Arterial Bleeding"}
						{talk "injuring"}
						{spawn "bloodstain" "basis" x}
						{call_synced "major_artery_bleeding_process"}
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
			{delay 5
				{if not dead
					{if tagged "moderate_artery_bleeding"
						("human_health" c(10))
						{damage_report "body" "<c(dd0000)>Moderate Arterial Bleeding"}
						{talk "injuring"}
						{spawn "bloodstain" "basis" x}
						{call_synced "moderate_artery_bleeding_process"}
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
			{delay 5
				{if not dead
					{if tagged "major_vein_bleeding"
						("human_health" c(15))
						{damage_report "body" "<c(dd0000)>Major Venous Bleeding"}
						{talk "injuring"}
						{spawn "bloodstain" "basis" x}
						{call_synced "major_vein_bleeding_process"}
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
			{delay 5
				{if not dead
					{if tagged "moderate_vein_bleeding"
						("human_health" c(5))
						{damage_report "body" "<c(dd0000)>Moderate Venous Bleeding"}
						{talk "injuring"}
						{spawn "bloodstain" "basis" x}
						{call_synced "moderate_vein_bleeding_process"}
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