#ifndef RhombusDrawer_H
#define RhombusDrawer_H

#include "Drawer.h"
/**
\brief Rhombus painter
*/
class RhombusDrawer final: public Drawer
{
protected:
	/**
	\brief implementation of the method responsible for drawing
	\param pRT pointer to drawing interface
	\param first Vertical diagonal
	\param second Horizontal diagonal
	\param third unused
	*/
	virtual void draw(ID2D1HwndRenderTarget* pRT, const std::uint32_t first, const std::uint32_t second, const std::uint32_t third) override
	{
		auto xCenter = pixelToDPIX(static_cast<float>(this->windowWidth) / 2) + xOffset / 2;
		auto yCenter = pixelToDPIY(static_cast<float>(windowHeight) / 2);
		auto VerticalCenter = pixelToDPIX(static_cast<float>(first / 2));
		auto HorizontalCenter = pixelToDPIY(static_cast<float>(second / 2));

		//build Triangle
		pRT->DrawLine({ xCenter - HorizontalCenter,yCenter }, { xCenter,yCenter + VerticalCenter }, brush, 2);
		pRT->DrawLine({ xCenter,yCenter + VerticalCenter }, { xCenter + HorizontalCenter,yCenter }, brush, 2);
		pRT->DrawLine({ xCenter + HorizontalCenter,yCenter }, { xCenter,yCenter - VerticalCenter }, brush, 2);
		pRT->DrawLine({ xCenter,yCenter - VerticalCenter }, { xCenter - HorizontalCenter,yCenter }, brush, 2);

	}
public:
	RhombusDrawer() = delete;
	RhombusDrawer(const RhombusDrawer&) = delete;
	RhombusDrawer(RhombusDrawer&&) = delete;
	/**
	\brief Constructor
	\param old Previous Drawer
	*/
	RhombusDrawer(Drawer&& old)
		:Drawer(std::move(old))
	{

	}
	virtual ~RhombusDrawer() = default;
};

#endif
