{budgets
	{vehicle
		{mode "standard"}
		{resource
			{start		%s}
			{finish		%f}
			{growTime	2600}		; in seconds
			{growTable	"0.65 0.65 0.65 0.70 0.70 0.70 0.75 0.75 0.75 0.80 0.80 0.80 0.80 0.80 0.80 0.85 0.85 0.85 0.90 0.90 0.90 0.90 0.90 0.90 1.00"}
			{payback
				{cp			"0		60		80 		100		140		160		180"} ; source code only supports 6 values
				{restore	"2.25	1.875	0.75	0.50	0.40	0.30	0.20"}
			}
		}
		{buttons "squad single supply support art lt mt ht td"}
	}
	{hero
		{resource
			{start %d}
		}
		{buttons "doctrine"}
		{tag "special"}
	}
}