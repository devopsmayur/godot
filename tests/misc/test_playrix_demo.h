/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#pragma once

#include "misc/playrix_demo/store_offer.h"

#include "tests/test_macros.h"

namespace TestPlayrixDemo {

TEST_CASE("[PlayrixDemo] format_price") {
	Offer offer;
	offer.price_eur = 4.99f;
	CHECK(StoreOffer::format_price(offer) == "4.99 EUR");
}

} // namespace TestPlayrixDemo
