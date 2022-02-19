#pragma once

#include "GameItemStorage.h"
#include "StaticData.h"

class StaticDataStorage {
public:
    void addPatch(int id, StaticData::ItemName name, int rarity, std::string_view inventoryImage)
    {
        paintKits.emplace_back(id, name);
        gameItems.addItem(StaticData::GameItem::patch(rarity, paintKits.size() - 1, inventoryImage));
    }

    void addGraffiti(int id, StaticData::ItemName name, int rarity, std::string_view inventoryImage)
    {
        paintKits.emplace_back(id, name);
        gameItems.addItem(StaticData::GameItem::graffiti(rarity, paintKits.size() - 1, inventoryImage));
        gameItems.addItem(StaticData::GameItem::sealedGraffiti(rarity, paintKits.size() - 1, inventoryImage));
    }

    void addSticker(int id, StaticData::ItemName name, int rarity, std::string_view inventoryImage, std::uint32_t tournamentID, TournamentTeam tournamentTeam, int tournamentPlayerID, bool isGoldenSticker)
    {
        stickerKits.emplace_back(id, name, tournamentID, tournamentTeam, tournamentPlayerID, isGoldenSticker);
        gameItems.addItem(StaticData::GameItem::sticker(rarity, stickerKits.size() - 1, inventoryImage));
    }

    void addMusic(int musicID, StaticData::ItemName name, std::string_view inventoryImage)
    {
        musicKits.emplace_back(musicID, name);
        gameItems.addItem(StaticData::GameItem::musicKit(3, musicKits.size() - 1, inventoryImage));
    }

    void addVanillaKnife(WeaponId weaponID, std::string_view inventoryImage)
    {
        gameItems.addItem(StaticData::GameItem::skin(6, weaponID, vanillaPaintIndex, inventoryImage));
    }

    void addCollectible(int rarity, WeaponId weaponID, bool isOriginal, std::string_view inventoryImage)
    {
        gameItems.addItem(StaticData::GameItem::collectible(rarity, weaponID, static_cast<std::size_t>(isOriginal), inventoryImage));
    }

    void addVanillaSkin(WeaponId weaponID, std::string_view inventoryImage)
    {
        gameItems.addItem(StaticData::GameItem::skin(0, weaponID, vanillaPaintIndex, inventoryImage));
    }

    void addServiceMedal(int rarity, std::uint32_t year, WeaponId weaponID, std::string_view inventoryImage)
    {
        gameItems.addItem(StaticData::GameItem::serviceMedal(rarity, weaponID, static_cast<std::size_t>(year), inventoryImage));
    }

    void addTournamentCoin(int rarity, WeaponId weaponID, std::uint32_t tournamentEventID, std::string_view iconPath)
    {
        gameItems.addItem(StaticData::GameItem::tournamentCoin(rarity, weaponID, static_cast<std::size_t>(tournamentEventID), iconPath));
    }

    void addPaintKit(int id, StaticData::ItemName name, float wearRemapMin, float wearRemapMax)
    {
        paintKits.emplace_back(id, name, wearRemapMin, wearRemapMax);
    }

    void addGlovesWithLastPaintKit(int rarity, WeaponId weaponID, std::string_view iconPath)
    {
        gameItems.addItem(StaticData::GameItem::gloves(rarity, weaponID, paintKits.size() - 1, iconPath));
    }

    void addSkinWithLastPaintKit(int rarity, WeaponId weaponID, std::string_view iconPath)
    {
        gameItems.addItem(StaticData::GameItem::skin(rarity, weaponID, paintKits.size() - 1, iconPath));
    }

    void addNameTag(int rarity, WeaponId weaponID, std::string_view iconPath)
    {
        gameItems.addItem(StaticData::GameItem::nameTag(rarity, weaponID, 0, iconPath));
    }

    const auto& getStickerKit(const StaticData::GameItem& item) const
    {
        assert(item.isSticker());
        return stickerKits[item.dataIndex];
    }

    const auto& getMusicKit(const StaticData::GameItem& item) const
    {
        assert(item.isMusic());
        return musicKits[item.dataIndex];
    }

    const auto& getPaintKit(const StaticData::GameItem& item) const
    {
        assert(item.hasPaintKit());
        return paintKits[item.dataIndex];
    }

    auto& getGameItems()
    {
        return gameItems;
    }

    const auto& getGameItems() const
    {
        return gameItems;
    }

    [[nodiscard]] std::uint16_t getServiceMedalYear(const StaticData::GameItem& serviceMedal) const noexcept
    {
        assert(serviceMedal.isServiceMedal());
        return static_cast<std::uint16_t>(serviceMedal.dataIndex);
    }

    [[nodiscard]] bool isCollectibleGenuine(const StaticData::GameItem& collectible) const noexcept
    {
        assert(collectible.isCollectible());
        return static_cast<bool>(collectible.dataIndex);
    }

private:
    static constexpr auto vanillaPaintIndex = 0;
    std::vector<StaticData::PaintKit> paintKits{ { 0, { "", L"" } } };
    std::vector<StaticData::StickerKit> stickerKits;
    std::vector<StaticData::MusicKit> musicKits;
    GameItemStorage gameItems;
};
