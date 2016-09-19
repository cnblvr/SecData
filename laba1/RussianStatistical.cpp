#include "RussianStatistical.h"
using namespace laba1;

double RussianStatistical::getFrequency(Char ch)
{
	switch(ch)
	{
	case L'à': return 0.07998;
	case L'á': return 0.01592;
	case L'â': return 0.04533;
	case L'ã': return 0.01687;
	case L'ä': return 0.02977;
	case L'å': return 0.08483;
	case L'¸': return 0.00013;
	case L'æ': return 0.0094;
	case L'ç': return 0.01641;
	case L'è': return 0.07367;
	case L'é': return 0.01208;
	case L'ê': return 0.03486;
	case L'ë': return 0.04343;
	case L'ì': return 0.03203;
	case L'í': return 0.067;
	case L'î': return 0.10983;
	case L'ï': return 0.02804;
	case L'ğ': return 0.04746;
	case L'ñ': return 0.05473;
	case L'ò': return 0.06318;
	case L'ó': return 0.02615;
	case L'ô': return 0.00267;
	case L'õ': return 0.00966;
	case L'ö': return 0.00486;
	case L'÷': return 0.0145;
	case L'ø': return 0.00718;
	case L'ù': return 0.00361;
	case L'ú': return 0.00037;
	case L'û': return 0.01898;
	case L'ü': return 0.01735;
	case L'ı': return 0.00331;
	case L'ş': return 0.00639;
	case L'ÿ': return 0.02001;
	};
}