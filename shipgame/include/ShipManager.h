#ifndef SHIPMANAGER_H
#define SHIPMANAGER_H

#include <vector>
#include <unordered_map>
#include "Ship.h"

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ (std::hash<T2>()(pair.second) << 1);
    }
};

class ShipManager {
public:
    struct ShipInfo {
        Ship ship;
        std::unordered_map<std::pair<int, int>, int, pair_hash> positionToSegmentIndex;

        ShipInfo(Ship&& ship, const std::vector<std::pair<int, int>>& positions);

        ShipInfo(const ShipInfo&) = delete;
        ShipInfo& operator=(const ShipInfo&) = delete;

        ShipInfo(ShipInfo&&) noexcept = default;
        ShipInfo& operator=(ShipInfo&&) noexcept = default;
    };

    ShipManager() = default;

    ShipManager(const ShipManager&) = delete;
    ShipManager& operator=(const ShipManager&) = delete;

    ShipManager(ShipManager&&) noexcept = default;
    ShipManager& operator=(ShipManager&&) noexcept = default;

    void addShip(Ship&& ship, const std::vector<std::pair<int, int>>& positions);
    void attackShip(int x, int y);
    bool allShipsDestroyed() const;
    bool isHit(int x, int y) const;
    bool isShipSegmentDamaged(int x, int y) const;
    bool isShipSegmentDestroyed(int x, int y) const;
    bool isShipSunkAt(int x, int y) const;

private:
    std::vector<ShipInfo> ships_;
};

#endif
