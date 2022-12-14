#ifndef TrapeziaDrawer_H
#define TrapeziaDrawer_H

#include "Drawer.h"
/**
\brief Trapezia painter
*/
class TrapeziaDrawer : public Drawer
{
protected:
	/**
	\brief implementation of the method responsible for drawing
	\param pRT pointer to drawing interface
	\param first Top base length
	\param second Bottom base length
	\param third Height
	*/
	virtual void draw(ID2D1HwndRenderTarget* pRT, const std::uint32_t first, const std::uint32_t second, const std::uint32_t third) override
	{

		auto xCenter = pixelToDPIX(static_cast<float>(this->windowWidth) / 2) + xOffset / 2;
		auto yCenter = pixelToDPIY(static_cast<float>(windowHeight) / 2);
		auto BottomCenter = pixelToDPIX(static_cast<float>(first) / 2);
		auto TopCenter = pixelToDPIX(static_cast<float>(second) / 2);
		auto HeightCenter = pixelToDPIY(static_cast<float>(third) / 2);
		//build Trapezia
		pRT->DrawLine({ xCenter - BottomCenter,yCenter - HeightCenter }, { xCenter - TopCenter,yCenter + HeightCenter },brush,2);
		pRT->DrawLine({ xCenter - TopCenter,yCenter + HeightCenter }, { xCenter + TopCenter,yCenter + HeightCenter },brush,2);
		pRT->DrawLine({ xCenter + TopCenter,yCenter + HeightCenter }, { xCenter + BottomCenter,yCenter - HeightCenter },brush,2);
		pRT->DrawLine({ xCenter + BottomCenter,yCenter - HeightCenter }, { xCenter - BottomCenter,yCenter - HeightCenter },brush,2);
	}
public:
	TrapeziaDrawer() = delete;
	TrapeziaDrawer(const TrapeziaDrawer&) = delete;
	TrapeziaDrawer(TrapeziaDrawer&&) = delete;
	/**
	\brief Constructor
	\param old Previous Drawer
	*/
	TrapeziaDrawer(Drawer&& old)
		:Drawer(std::move(old))
	{

	}
	virtual ~TrapeziaDrawer() = default;
};

#endif
