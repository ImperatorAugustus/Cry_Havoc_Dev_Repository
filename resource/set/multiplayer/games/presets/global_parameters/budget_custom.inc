{budgets
	{vehicle
		{mode "custom"}
		{resource
			{start		%start}
			{finish		%finish}
			{growTime	2400}		; in seconds
			{growTable	"0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.80 0.82 0.84 0.86 0.88 0.9 0.9 0.9 0.9 1.0 1.0 1.0"}
			{payback
				{cp			"0		80		95		110		125		200	"} ; source code only supports 6 values
				{restore	"1.00	0.8		0.6		0.4		0.25	0.10"}
			}
			{limitmin	10}
			{limitmax	500000}
			{speedset	"2000 2500 3000 3500 4000 4500 5000 6000 10000"}
		}
		{buttons "squad single supply support art lt mt ht td"}
	}
	{hero
		{resource
			{start %doctrine}
		}
		{buttons "doctrine"}
		{tag "special"}
	}
}