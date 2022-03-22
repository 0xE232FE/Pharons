#include "Storage.h"

namespace game_items
{

void Storage::addPatch(int id, ItemName name, EconRarity rarity, std::string_view iconPath)
{
    patchKits.emplace_back(id, name);
    addItem(Item::Type::Patch, rarity, WeaponId::Patch, patchKits.size() - 1, iconPath);
}

void Storage::addGraffiti(int id, ItemName name, EconRarity rarity, std::string_view iconPath)
{
    graffitiKits.emplace_back(id, name);
    const auto index = graffitiKits.size() - 1;
    addItem(Item::Type::Graffiti, rarity, WeaponId::SealedGraffiti, index, iconPath);
}

void Storage::addSticker(int id, ItemName name, EconRarity rarity, std::string_view iconPath, std::uint32_t tournamentID, TournamentTeam tournamentTeam, int tournamentPlayerID, bool isGoldenSticker)
{
    stickerKits.emplace_back(id, name, tournamentID, tournamentTeam, tournamentPlayerID, isGoldenSticker);
    addItem(Item::Type::Sticker, rarity, WeaponId::Sticker, stickerKits.size() - 1, iconPath);
}

void Storage::addMusic(int musicID, ItemName name, std::string_view iconPath)
{
    musicKits.emplace_back(musicID, name);
    addItem(Item::Type::Music, EconRarity::Blue, WeaponId::MusicKit, musicKits.size() - 1, iconPath);
}

void Storage::addVanillaKnife(WeaponId weaponID, std::string_view iconPath)
{
    addItem(Item::Type::Skin, EconRarity::Red, weaponID, vanillaPaintIndex, iconPath);
}

void Storage::addCollectible(EconRarity rarity, WeaponId weaponID, bool isOriginal, std::string_view iconPath)
{
    addItem(Item::Type::Collectible, rarity, weaponID, static_cast<std::size_t>(isOriginal), iconPath);
}

void Storage::addVanillaSkin(WeaponId weaponID, std::string_view iconPath)
{
    addItem(Item::Type::Skin, EconRarity::Default, weaponID, vanillaPaintIndex, iconPath);
}

void Storage::addServiceMedal(EconRarity rarity, std::uint32_t year, WeaponId weaponID, std::string_view iconPath)
{
    addItem(Item::Type::ServiceMedal, rarity, weaponID, static_cast<std::size_t>(year), iconPath);
}

void Storage::addTournamentCoin(EconRarity rarity, WeaponId weaponID, std::uint32_t tournamentEventID, std::string_view iconPath)
{
    addItem(Item::Type::TournamentCoin, rarity, weaponID, static_cast<std::size_t>(tournamentEventID), iconPath);
}

void Storage::addPaintKit(int id, ItemName name, float wearRemapMin, float wearRemapMax)
{
    paintKits.emplace_back(id, name, wearRemapMin, wearRemapMax);
}

void Storage::addGlovesWithLastPaintKit(EconRarity rarity, WeaponId weaponID, std::string_view iconPath)
{
    addItem(Item::Type::Gloves, rarity, weaponID, paintKits.size() - 1, iconPath);
}

void Storage::addSkinWithLastPaintKit(EconRarity rarity, WeaponId weaponID, std::string_view iconPath)
{
    addItem(Item::Type::Skin, rarity, weaponID, paintKits.size() - 1, iconPath);
}

void Storage::addNameTag(EconRarity rarity, WeaponId weaponID, std::string_view iconPath)
{
    addItem(Item::Type::NameTag, rarity, weaponID, 0, iconPath);
}

void Storage::addAgent(EconRarity rarity, WeaponId weaponID, std::string_view iconPath)
{
    addItem(Item::Type::Agent, rarity, weaponID, 0, iconPath);
}

void Storage::addCase(EconRarity rarity, WeaponId weaponID, std::size_t descriptorIndex, std::string_view iconPath)
{
    addItem(Item::Type::Case, rarity, weaponID, descriptorIndex, iconPath);
}

void Storage::addCaseKey(EconRarity rarity, WeaponId weaponID, std::string_view iconPath)
{
    addItem(Item::Type::CaseKey, rarity, weaponID, 0, iconPath);
}

void Storage::addOperationPass(EconRarity rarity, WeaponId weaponID, std::string_view iconPath)
{
    addItem(Item::Type::OperationPass, rarity, weaponID, 0, iconPath);
}

void Storage::addStatTrakSwapTool(EconRarity rarity, WeaponId weaponID, std::string_view iconPath)
{
    addItem(Item::Type::StatTrakSwapTool, rarity, weaponID, 0, iconPath);
}

void Storage::addSouvenirToken(EconRarity rarity, WeaponId weaponID, std::uint32_t tournamentEventID, std::string_view iconPath)
{
    addItem(Item::Type::SouvenirToken, rarity, weaponID, static_cast<std::size_t>(tournamentEventID), iconPath);
}

void Storage::addViewerPass(EconRarity rarity, WeaponId weaponID, std::uint32_t tournamentEventID, std::string_view iconPath)
{
    addItem(Item::Type::ViewerPass, rarity, weaponID, static_cast<std::size_t>(tournamentEventID), iconPath);
}

void Storage::compress()
{
    paintKits.shrink_to_fit();
    stickerKits.shrink_to_fit();
    musicKits.shrink_to_fit();
    graffitiKits.shrink_to_fit();
    patchKits.shrink_to_fit();
    items.shrink_to_fit();
}

}
