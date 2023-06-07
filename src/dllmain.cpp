#pragma comment(lib, "../SDK/lib/bedrock_server_api.lib")
#pragma comment(lib, "../SDK/lib/bedrock_server_var.lib")
#pragma comment(lib, "../SDK/lib/SymDBHelper.lib")
#pragma comment(lib, "../SDK/lib/LiteLoader.lib")

#include <llapi/HookAPI.h>
#include <llapi/mc/Block.hpp>
#include <llapi/mc/BlockSource.hpp>
#include <llapi/mc/BlockPos.hpp>
#include <llapi/mc/Level.hpp>

TClasslessInstanceHook(void, "?startFalling@FallingBlock@@MEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@_N@Z",
					   class BlockSource& a2, class BlockPos const& a3, class Block const& a4, bool a5) {
	if (!Level::getBlock(a3.add(0, -1), &a2)->isAir())
		return;
	original(this, a2, a3, a4, a5);
}
