#pragma comment(lib, "../SDK/lib/bedrock_server_api.lib")
#pragma comment(lib, "../SDK/lib/bedrock_server_var.lib")
#pragma comment(lib, "../SDK/lib/SymDBHelper.lib")
#pragma comment(lib, "../SDK/lib/LiteLoader.lib")

#include <llapi/HookAPI.h>
#include <llapi/mc/BlockLegacy.hpp>
#include <llapi/mc/Actor.hpp>
#include <llapi/mc/Level.hpp>
#include <llapi/mc/Vec3.hpp>
#include <llapi/mc/Block.hpp>

std::array<std::string, 2> block_list{
    "minecraft:water",
    "minecraft:big_dripleaf"
};

TInstanceHook(bool, "?shouldStopFalling@BlockLegacy@@UEBA_NAEAVActor@@@Z", BlockLegacy, Actor* a2) {
    bool result = original(this, a2);
    if (result) {
        Vec3 const& pos = a2->getPosition();
        Block* block = Level::getBlock(pos.sub(Vec3(0, 1, 0)), a2->getDimensionId());
        std::string name = block->getTypeName();
        if (std::find(block_list.begin(), block_list.end(), name) != block_list.end()) {
            return false;
        }
    }
    return result;
}
