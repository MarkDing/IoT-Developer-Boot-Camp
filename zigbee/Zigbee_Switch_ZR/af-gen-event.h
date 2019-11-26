// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// Enclosing macro to prevent multiple inclusion
#ifndef __AF_GEN_EVENT__
#define __AF_GEN_EVENT__


// Code used to configure the cluster event mechanism
#define EMBER_AF_GENERATED_EVENT_CODE \
  extern EmberEventControl emberAfPluginButtonInterfaceButton0PressedEventControl; \
  extern EmberEventControl emberAfPluginButtonInterfaceButton0ReleasedEventControl; \
  extern EmberEventControl emberAfPluginButtonInterfaceButton1PressedEventControl; \
  extern EmberEventControl emberAfPluginButtonInterfaceButton1ReleasedEventControl; \
  extern EmberEventControl emberAfPluginButtonInterfaceButtonTimeoutEventControl; \
  extern EmberEventControl emberAfPluginNetworkSteeringFinishSteeringEventControl; \
  extern EmberEventControl emberAfPluginScanDispatchScanEventControl; \
  extern EmberEventControl emberAfPluginUpdateTcLinkKeyBeginTcLinkKeyUpdateEventControl; \
  extern EmberEventControl ledBlinkingEventControl; \
  extern void emberAfPluginButtonInterfaceButton0PressedEventHandler(void); \
  extern void emberAfPluginButtonInterfaceButton0ReleasedEventHandler(void); \
  extern void emberAfPluginButtonInterfaceButton1PressedEventHandler(void); \
  extern void emberAfPluginButtonInterfaceButton1ReleasedEventHandler(void); \
  extern void emberAfPluginButtonInterfaceButtonTimeoutEventHandler(void); \
  extern void emberAfPluginNetworkSteeringFinishSteeringEventHandler(void); \
  extern void emberAfPluginScanDispatchScanEventHandler(void); \
  extern void emberAfPluginUpdateTcLinkKeyBeginTcLinkKeyUpdateEventHandler(void); \
  extern void ledBlinkingEventHandler(void); \


// EmberEventData structs used to populate the EmberEventData table
#define EMBER_AF_GENERATED_EVENTS   \
  { &emberAfPluginButtonInterfaceButton0PressedEventControl, emberAfPluginButtonInterfaceButton0PressedEventHandler }, \
  { &emberAfPluginButtonInterfaceButton0ReleasedEventControl, emberAfPluginButtonInterfaceButton0ReleasedEventHandler }, \
  { &emberAfPluginButtonInterfaceButton1PressedEventControl, emberAfPluginButtonInterfaceButton1PressedEventHandler }, \
  { &emberAfPluginButtonInterfaceButton1ReleasedEventControl, emberAfPluginButtonInterfaceButton1ReleasedEventHandler }, \
  { &emberAfPluginButtonInterfaceButtonTimeoutEventControl, emberAfPluginButtonInterfaceButtonTimeoutEventHandler }, \
  { &emberAfPluginNetworkSteeringFinishSteeringEventControl, emberAfPluginNetworkSteeringFinishSteeringEventHandler }, \
  { &emberAfPluginScanDispatchScanEventControl, emberAfPluginScanDispatchScanEventHandler }, \
  { &emberAfPluginUpdateTcLinkKeyBeginTcLinkKeyUpdateEventControl, emberAfPluginUpdateTcLinkKeyBeginTcLinkKeyUpdateEventHandler }, \
  { &ledBlinkingEventControl, ledBlinkingEventHandler }, \


#define EMBER_AF_GENERATED_EVENT_STRINGS   \
  "Button Interface Plugin Button0Pressed",  \
  "Button Interface Plugin Button0Released",  \
  "Button Interface Plugin Button1Pressed",  \
  "Button Interface Plugin Button1Released",  \
  "Button Interface Plugin ButtonTimeout",  \
  "Network Steering Plugin FinishSteering",  \
  "Scan Dispatch Plugin Scan",  \
  "Update TC Link Key Plugin BeginTcLinkKeyUpdate",  \
  "Event data",  \


#endif // __AF_GEN_EVENT__
