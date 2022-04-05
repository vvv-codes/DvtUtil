#include "Papyrus/Registration.h"

#include "Papyrus/Actor.h"
#include "Papyrus/Faction.h"
#include "Papyrus/Experiments.h"
#include "Papyrus/FormList.h"
#include "Papyrus/ObjectREFR.h"
#include "Papyrus/Race.h"
#include "Papyrus/Spell.h"
#include "Papyrus/String.h"
#include "Papyrus/Time.h"


namespace Papyrus
{
	auto Register() -> void
	{
		const auto papyrus = SKSE::GetPapyrusInterface();

		papyrus->Register(Papyrus::Actor::RegisterFuncs);
		logger::info("Registered actor functions");

		papyrus->Register(Papyrus::Faction::RegisterFuncs);
		logger::info("Registered faction functions");

		papyrus->Register(Papyrus::FormList::RegisterFuncs);
		logger::info("Registered formlist functions");

		papyrus->Register(Papyrus::ObjectREFR::RegisterFuncs);
		logger::info("Registered object reference functions");

		papyrus->Register(Papyrus::Race::RegisterFuncs);
		logger::info("Registered race functions");

		papyrus->Register(Papyrus::Spell::RegisterFuncs);
		logger::info("Registered spell functions");

		papyrus->Register(Papyrus::String::RegisterFuncs);
		logger::info("Registered string functions");

		papyrus->Register(Papyrus::Time::RegisterFuncs);
		logger::info("Registered time functions");

		papyrus->Register(Papyrus::Experiments::RegisterFuncs);
		logger::info("Registered experimental functions");
	}
}