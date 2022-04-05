#pragma once

#include "ActorValueHelper.h"

#include "Race.h"

namespace Papyrus::Race
{
	auto GetRaceSkills(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> std::vector<RE::BSFixedString>
	{
		std::vector<RE::BSFixedString> vec;

		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return vec;
		}

		for (const auto& [skill, bonus] : a_race->data.skillBoosts) {
			const auto skillValue = static_cast<RE::ActorValue>(skill.get());
			const auto skillName = ActorValueHelper::ActorValueToString(skillValue);
			vec.push_back(skillName);
		}

		return vec;
	}

	auto GetRaceMaleHeight(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.height[RE::SEXES::kMale];
	}

	auto GetRaceFemaleHeight(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.height[RE::SEXES::kFemale];
	}

	auto GetRaceMaleWeight(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.weight[RE::SEXES::kMale];
	}

	auto GetRaceFemaleWeight(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.weight[RE::SEXES::kFemale];
	}

	auto GetRaceStartingHealth(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.startingHealth;
	}

	auto GetRaceStartingMagicka(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.startingMagicka;
	}

	auto GetRaceStartingStamina(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.startingStamina;
	}

	auto GetRaceCarryWeight(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.baseCarryWeight;
	}

	auto GetRaceMass(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.baseMass;
	}

	auto GetRaceHealthRegen(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.healthRegen;
	}

	auto GetRaceMagickaRegen(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.magickaRegen;
	}

	auto GetRaceStaminaRegen(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.staminaRegen;
	}

	auto GetRaceUnarmedDamage(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.unarmedDamage;
	}

	auto GetRaceUnarmedReach(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESRace* a_race) -> float
	{
		if (!a_race) {
			a_vm->TraceStack("akRace cannot be None", a_stackID, Severity::kInfo);
			return -1;
		}

		return a_race->data.unarmedReach;
	}

	auto RegisterFuncs(VM* a_vm) -> bool
	{
		if (!a_vm) {
			logger::info("PapyrusRace - cannot get VMState");
			return false;
		}

		a_vm->RegisterFunction("GetRaceSkills", Plugin::NAME, GetRaceSkills);

		a_vm->RegisterFunction("GetRaceMaleHeight", Plugin::NAME, GetRaceMaleHeight);
		a_vm->RegisterFunction("GetRaceMaleWeight", Plugin::NAME, GetRaceMaleWeight);
		a_vm->RegisterFunction("GetRaceFemaleHeight", Plugin::NAME, GetRaceFemaleHeight);
		a_vm->RegisterFunction("GetRaceFemaleWeight", Plugin::NAME, GetRaceFemaleWeight);

		a_vm->RegisterFunction("GetRaceStartingHealth", Plugin::NAME, GetRaceStartingHealth);
		a_vm->RegisterFunction("GetRaceStartingMagicka", Plugin::NAME, GetRaceStartingMagicka);
		a_vm->RegisterFunction("GetRaceStartingStamina", Plugin::NAME, GetRaceStartingStamina);

		a_vm->RegisterFunction("GetRaceCarryWeight", Plugin::NAME, GetRaceCarryWeight);
		a_vm->RegisterFunction("GetRaceMass", Plugin::NAME, GetRaceMass);

		a_vm->RegisterFunction("GetRaceHealthRegen", Plugin::NAME, GetRaceHealthRegen);
		a_vm->RegisterFunction("GetRaceMagickaRegen", Plugin::NAME, GetRaceMagickaRegen);
		a_vm->RegisterFunction("GetRaceStaminaRegen", Plugin::NAME, GetRaceStaminaRegen);

		a_vm->RegisterFunction("GetRaceUnarmedDamage", Plugin::NAME, GetRaceUnarmedDamage);
		a_vm->RegisterFunction("GetRaceUnarmedReach", Plugin::NAME, GetRaceUnarmedReach);

		return true;
	}
}