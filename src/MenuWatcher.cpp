#include <Configs.h>
#include <Globals.h>
#include <MenuWatcher.h>
#include <Utils.h>

MenuWatcher* MenuWatcher::instance = nullptr;
RE::BSEventNotifyControl MenuWatcher::ProcessEvent(const RE::MenuOpenCloseEvent& evn, [[maybe_unused]] RE::BSTEventSource<RE::MenuOpenCloseEvent>* src)
{
	if (!evn.opening && evn.menuName == "HUDMenu") {
		if (Utils::IsInPA(Globals::p)) {
			Utils::CalculateArmorTiers(Globals::p);
		}
	}
	return RE::BSEventNotifyControl::kContinue;
}
