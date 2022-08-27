#include "TeamConfirmControl.hh"

#include "game/ui/SectionManager.hh"
#include "game/util/Registry.hh"

namespace UI {

namespace GroupId {

enum {
    Loop = 0,
    Select = 1,
    Select2 = 2,
    Color = 3,
    Position = 4,
};

} // namespace GroupId

TeamConfirmControl::TeamConfirmControl() = default;

TeamConfirmControl::~TeamConfirmControl() = default;

void TeamConfirmControl::load() {
    const char *groups[] = {
        "Loop",
        "Loop",
        nullptr,
        "Select",
        "SelectOn",
        "SelectOff",
        nullptr,
        "Select2",
        "Select2On",
        "Select2Off",
        nullptr,
        "Color",
        "Color",
        nullptr,
        "Position",
        "Position",
        nullptr,
        nullptr,
    };
    LayoutUIControl::load("control", "TeamConfirm", "TeamConfirm", groups);
}

void TeamConfirmControl::refresh(u32 playerId, u32 characterId, u32 colorId, u32 positionId) {
    auto *context = SectionManager::Instance()->globalContext();
    u32 localPlayerCount = context->m_localPlayerCount;
    setMessage("mii_name", Registry::GetCharacterMessageId(characterId, true));
    setPicture("chara_icon", Registry::GetCharacterPane(characterId));
    setPicture("chara_icon_sha", Registry::GetCharacterPane(characterId));
    m_animator.setAnimation(GroupId::Loop, 0, 0.0f);
    m_animator.setAnimation(GroupId::Select, playerId >= localPlayerCount, 0.0f);
    m_animator.setAnimation(GroupId::Select2, playerId >= localPlayerCount, 0.0f);
    m_animator.setAnimationInactive(GroupId::Color, 0, colorId);
    m_animator.setAnimationInactive(GroupId::Position, 0, positionId);
}

} // namespace UI