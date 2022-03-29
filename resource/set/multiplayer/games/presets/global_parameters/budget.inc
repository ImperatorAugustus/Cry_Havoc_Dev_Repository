		{budgets
			{vehicle
				{mode "standard"}
				{resource
					{start		%s}
					{finish		%f}
					{growTime	2400}		; in seconds
					{growTable	"0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.82 0.84 0.86 0.88 0.9 0.90 0.9 0.85 0.8 0.75 0.7"}
					{payback
						{cp			"0		100		150		200		250		275"} ; keep only 6 values
						{restore		"4.00		1.1		0.75 		0.25		0.10		0.05"}
					}
				}
				{buttons "inf1 inf2 empl vehicles tanks"}
			}
			{hero
				{resource 
					{start %d}
				} 
				{buttons "doctrine"}
				{tag "special"}
			}
		}