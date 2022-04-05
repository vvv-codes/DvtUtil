#pragma once

#include "ObjectREFR.h"

namespace Papyrus::ObjectREFR
{
	auto FindNearbyActors(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESObjectREFR* a_origin, float a_radius) -> std::vector<RE::Actor*>
	{
		std::vector<RE::Actor*> vec;

		if (!a_origin) {
			a_vm->TraceStack("akOrigin cannot be None", a_stackID, Severity::kInfo);
			return vec;
		}

		if (const auto TES = RE::TES::GetSingleton(); TES) {
			const auto formType = RE::FormType::NPC;

			TES->ForEachReferenceInRange(a_origin, a_radius, [&](RE::TESObjectREFR& a_ref) {
				auto base = a_ref.GetBaseObject();
				if (a_ref.As<RE::TESObjectREFR>() != a_origin && (a_ref.Is(formType) || base && base->Is(formType))) {
					if (auto actor = a_ref.As<RE::Actor>(); actor) {
						vec.push_back(actor);
					}
				}
				return true;
			});
		}

		return vec;
	}

	auto FindNearbyBooks(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESObjectREFR* a_origin, float a_radius) -> std::vector<RE::TESObjectREFR*>
	{
		std::vector<RE::TESObjectREFR*> vec;

		if (!a_origin) {
			a_vm->TraceStack("akOrigin cannot be None", a_stackID, Severity::kInfo);
			return vec;
		}

		if (const auto TES = RE::TES::GetSingleton(); TES) {
			const auto formType = RE::FormType::Book;

			TES->ForEachReferenceInRange(a_origin, a_radius, [&](RE::TESObjectREFR& a_ref) {
				auto base = a_ref.GetBaseObject();
				if (a_ref.As<RE::TESObjectREFR>() != a_origin && (a_ref.Is(formType) || base && base->Is(formType))) {
					vec.push_back(&a_ref);
				}
				return true;
			});
		}

		return vec;
	}

	auto FindNearbyCommandedActors(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESObjectREFR* a_origin, float a_radius) -> std::vector<RE::Actor*>
	{
		std::vector<RE::Actor*> vec;

		if (!a_origin) {
			a_vm->TraceStack("akOrigin cannot be None", a_stackID, Severity::kInfo);
			return vec;
		}

		if (const auto TES = RE::TES::GetSingleton(); TES) {
			const auto formType = RE::FormType::NPC;

			TES->ForEachReferenceInRange(a_origin, a_radius, [&](RE::TESObjectREFR& a_ref) {
				auto base = a_ref.GetBaseObject();
				if (a_ref.As<RE::TESObjectREFR>() != a_origin && (a_ref.Is(formType) || base && base->Is(formType))) {
					if (auto actor = a_ref.As<RE::Actor>(); actor) {
						if (actor->IsCommandedActor()) {
							if (const auto commandingActorHandle = actor->GetCommandingActor(); commandingActorHandle) {
								const auto commandingActorPtr = commandingActorHandle.get();
								const auto commandingActor = commandingActorPtr.get();

								if (commandingActor != nullptr && commandingActor == a_origin) {
									vec.push_back(actor);
								}
							}
						}
					}
				}
				return true;
			});
		}

		return vec;
	}

	auto FindNearbyFollowers(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, float a_radius) -> std::vector<RE::Actor*>
	{
		std::vector<RE::Actor*> vec;

		if (const auto TES = RE::TES::GetSingleton(); TES) {
			if (const auto player = RE::PlayerCharacter::GetSingleton(); player) {
				const auto formType = RE::FormType::NPC;

				TES->ForEachReferenceInRange(player, a_radius, [&](RE::TESObjectREFR& a_ref) {
					auto base = a_ref.GetBaseObject();
					if (a_ref.As<RE::TESObjectREFR>() != player && (a_ref.Is(formType) || base && base->Is(formType))) {
						if (auto actor = a_ref.As<RE::Actor>(); actor) {
							if (actor->IsPlayerTeammate()) {
								vec.push_back(actor);
							} else if (actor->IsCommandedActor() || actor->IsSummoned()) {
								if (const auto commandingActorHandle = actor->GetCommandingActor(); commandingActorHandle) {
									const auto commandingActorPtr = commandingActorHandle.get();
									const auto commandingActor = commandingActorPtr.get();

									if (commandingActor != nullptr && commandingActor == player) {
										vec.push_back(actor);
									}
								}
							}
						}
					}
					return true;
				});
			}
		}

		return vec;
	}

	auto FindNearbySummons(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, RE::TESObjectREFR* a_origin, float a_radius) -> std::vector<RE::Actor*>
	{
		std::vector<RE::Actor*> vec;

		if (!a_origin) {
			a_vm->TraceStack("akOrigin cannot be None", a_stackID, Severity::kInfo);
			return vec;
		}

		if (const auto TES = RE::TES::GetSingleton(); TES) {
			const auto formType = RE::FormType::NPC;

			TES->ForEachReferenceInRange(a_origin, a_radius, [&](RE::TESObjectREFR& a_ref) {
				auto base = a_ref.GetBaseObject();
				if (a_ref.As<RE::TESObjectREFR>() != a_origin && (a_ref.Is(formType) || base && base->Is(formType))) {
					if (auto actor = a_ref.As<RE::Actor>(); actor) {
						if (actor->IsSummoned()) {
							vec.push_back(actor);
						}
					}
				}
				return true;
			});
		}

		return vec;
	}

	auto FindNearbyTeammates(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*, float a_radius) -> std::vector<RE::Actor*>
	{
		std::vector<RE::Actor*> vec;

		if (const auto TES = RE::TES::GetSingleton(); TES) {
			if (const auto player = RE::PlayerCharacter::GetSingleton(); player) {
				if (player->teammateCount > 0) {
					const auto formType = RE::FormType::NPC;

					TES->ForEachReferenceInRange(player, a_radius, [&](RE::TESObjectREFR& a_ref) {
						auto base = a_ref.GetBaseObject();
						if (a_ref.As<RE::TESObjectREFR>() != player && (a_ref.Is(formType) || base && base->Is(formType))) {
							if (auto actor = a_ref.As<RE::Actor>(); actor) {
								if (actor->IsPlayerTeammate()) {
									vec.push_back(actor);
								}
							}
						}
						return true;
					});
				}
			}
		}

		return vec;
	}

	auto RegisterFuncs(VM* a_vm) -> bool
	{
		if (!a_vm) {
			logger::info("PapyrusObjectREFR - couldn't get VMState");
			return false;
		}

		a_vm->RegisterFunction("FindNearbyActors", Plugin::NAME, FindNearbyActors);
		a_vm->RegisterFunction("FindNearbyBooks", Plugin::NAME, FindNearbyBooks);
		a_vm->RegisterFunction("FindNearbyCommandedActors", Plugin::NAME, FindNearbyCommandedActors);
		a_vm->RegisterFunction("FindNearbyFollowers", Plugin::NAME, FindNearbyFollowers);
		a_vm->RegisterFunction("FindNearbySummons", Plugin::NAME, FindNearbySummons);
		a_vm->RegisterFunction("FindNearbyTeammates", Plugin::NAME, FindNearbyTeammates);

		return true;
	}
}