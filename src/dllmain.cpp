#pragma comment(lib, "../SDK/lib/bedrock_server_api.lib")
#pragma comment(lib, "../SDK/lib/bedrock_server_var.lib")
#pragma comment(lib, "../SDK/lib/SymDBHelper.lib")
#pragma comment(lib, "../SDK/lib/LiteLoader.lib")

#include <llapi/HookAPI.h>
#include <llapi/mc/FallingBlock.hpp>
#include <llapi/mc/BlockSource.hpp>
#include <llapi/mc/BlockPos.hpp>

TClasslessInstanceHook(bool, "?isFreeToFall@FallingBlock@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z",
                       BlockSource& a2, BlockPos const& a3) {
    bool result = original(this, a2, a3);
    if (result && a2.getBlock(a3.x, a3.y - 1, a3.z).getTypeName() == "minecraft:big_dripleaf")
        return false;
    return result;
}
