// SPDX-License-Identifier: Apache-2.0

#include "common_types.hpp"

#include <phosphor-logging/lg2.hpp>
#include <sdbusplus/bus.hpp>
#include <sdeventplus/event.hpp>

int main()
{
    auto eventLoopRet = 0;
    try
    {
        lg2::info("Welcome to RBMC Data-Sync");

        auto bus = sdbusplus::bus::new_default();

        auto event = sdeventplus::Event::get_default();
        bus.attach_event(event.get(), SD_EVENT_PRIORITY_NORMAL);

        /**
         * The name should be claimed only after the D-Bus service has been
         * fully initialized to prevent the "InterfacesAdded" signal from being
         * sent when restoring an existing object from its persisted file.
         */
        bus.request_name(rbmc::data_sync::type::DATA_SYNC_BUSNAME);

        // The following statement should be the last step to enter this app
        // into the loop for processing D-Bus services.
        eventLoopRet = event.loop();
    }
    catch (std::exception& e)
    {
        lg2::error("Exception: {EXCEPTION}", "EXCEPTION", e);
    }

    return eventLoopRet;
}
