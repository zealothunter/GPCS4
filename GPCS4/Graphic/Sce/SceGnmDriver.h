#pragma once

#include "GPCS4Common.h"
#include "SceVideoOut.h"

#include "../Gnm/GnmCmdStream.h"
#include "../Gnm/GnmCommandBufferDraw.h"

#include <memory>

namespace sce
{;

class SceGnmDriver
{
public:
	SceGnmDriver(std::shared_ptr<SceVideoOut>& videoOut);
	~SceGnmDriver();

	bool allocateCommandBuffers(uint32_t bufferNum);

	int submitAndFlipCommandBuffers(uint32_t count,
		void *dcbGpuAddrs[], uint32_t *dcbSizesInBytes,
		void *ccbGpuAddrs[], uint32_t *ccbSizesInBytes,
		uint32_t videoOutHandle, uint32_t displayBufferIndex,
		uint32_t flipMode, int64_t flipArg);

	int sceGnmSubmitDone(void);

private:
	std::shared_ptr<SceVideoOut> m_videoOut;
	std::vector<std::unique_ptr<GnmCmdStream>> m_commandParsers;
	std::vector<std::shared_ptr<GnmCommandBuffer>> m_commandBuffers;
};

}  //sce