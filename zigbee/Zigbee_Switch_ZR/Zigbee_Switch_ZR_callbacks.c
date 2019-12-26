/***************************************************************************//**
 * @file
 * @brief Callback implementation for ZigbeeMinimal sample application.
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

// This callback file is created for your convenience. You may add application
// code to this file. If you regenerate this file over a previous version, the
// previous version will be overwritten and any code you have added will be
// lost.

#include "app/framework/include/af.h"

/** @brief Stack Status
 *
 * This function is called by the application framework from the stack status
 * handler.  This callbacks provides applications an opportunity to be notified
 * of changes to the stack status and take appropriate action.  The return code
 * from this callback is ignored by the framework.  The framework will always
 * process the stack status after the callback returns.
 *
 * @param status   Ver.: always
 */
bool emberAfStackStatusCallback(EmberStatus status)
{
  // This value is ignored by the framework.
  return false;
}

/** @brief Complete
 *
 * This callback is fired when the Network Steering plugin is complete.
 *
 * @param status On success this will be set to EMBER_SUCCESS to indicate a
 * network was joined successfully. On failure this will be the status code of
 * the last join or scan attempt. Ver.: always
 * @param totalBeacons The total number of 802.15.4 beacons that were heard,
 * including beacons from different devices with the same PAN ID. Ver.: always
 * @param joinAttempts The number of join attempts that were made to get onto
 * an open Zigbee network. Ver.: always
 * @param finalState The finishing state of the network steering process. From
 * this, one is able to tell on which channel mask and with which key the
 * process was complete. Ver.: always
 */
void emberAfPluginNetworkSteeringCompleteCallback(EmberStatus status,
                                                  uint8_t totalBeacons,
                                                  uint8_t joinAttempts,
                                                  uint8_t finalState)
{
  emberAfCorePrintln("%p network %p: 0x%X", "Join", "complete", status);
}

// Sending-OnOff-Commands: Step 2
void emberAfPluginButtonInterfaceButton0PressedShortCallback(uint16_t timePressedMs)
{
  emberAfCorePrintln("Button0 is pressed for %d milliseconds",timePressedMs);

  EmberStatus status;

  emberAfFillCommandOnOffClusterOn()
  emberAfCorePrintln("Command is zcl on-off ON");

  emberAfSetCommandEndpoints(emberAfPrimaryEndpoint(),1);
  status=emberAfSendCommandUnicast(EMBER_OUTGOING_DIRECT, 0x0000);

  if(status == EMBER_SUCCESS){
    emberAfCorePrintln("Command is successfully sent");
  }else{
    emberAfCorePrintln("Failed to send");
    emberAfCorePrintln("Status code: 0x%x",status);
  }
}

void emberAfPluginButtonInterfaceButton1PressedShortCallback(uint16_t timePressedMs)
{
  emberAfCorePrintln("Button1 is pressed for %d milliseconds",timePressedMs);

  EmberStatus status;

  emberAfFillCommandOnOffClusterOff()
  emberAfCorePrintln("Command is zcl on-off OFF");

  emberAfSetCommandEndpoints(emberAfPrimaryEndpoint(),1);
  status=emberAfSendCommandUnicast(EMBER_OUTGOING_DIRECT, 0x0000);

  if(status == EMBER_SUCCESS){
    emberAfCorePrintln("Command is successfully sent");
  }else{
    emberAfCorePrintln("Failed to send");
    emberAfCorePrintln("Status code: 0x%x",status);
  }
}

// Using-event: Step 3
EmberEventControl ledBlinkingEventControl;

// Non-volatile Data Storage: Step 1
ledOnOffStatus_t led1OnOffStatus;

void emberAfMainInitCallback(void)
{
  // Non-volatile Data Storage: Step 4
  tokTypeMfgString mfgString;
  halCommonGetMfgToken(mfgString, TOKEN_MFG_STRING);
  emberAfAppPrintln("MFG String: %s", mfgString);

  // Non-volatile Data Storage: Step 1
  // Retrieve the LED1 status before reset/power-off from the token
  halCommonGetToken(&led1OnOffStatus, TOKEN_LED1_ON_OFF);

  emberAfCorePrintln("The LED%d previous status is %s", led1OnOffStatus.ledIndex, (led1OnOffStatus.ledOnOff)?"On":"Off");

  // Restore the LED1 status during initialization
  if(led1OnOffStatus.ledOnOff){
	  halSetLed(led1OnOffStatus.ledIndex);
  }
  else{
	  halClearLed(led1OnOffStatus.ledIndex);
  }

  emberEventControlSetDelayMS(ledBlinkingEventControl, 5000);
}

void ledBlinkingEventHandler(void)
{
  // First thing to do inside a delay event is to disable the event till next usage
  emberEventControlSetInactive(ledBlinkingEventControl);

//  halToggleLed(1);

  // halToggleLed(1);
  // Non-volatile Data Storage: Step 2
  // Retrieve the previous status of LED1
  halCommonGetToken(&led1OnOffStatus, TOKEN_LED1_ON_OFF);
  halToggleLed(led1OnOffStatus.ledIndex);
  led1OnOffStatus.ledOnOff = !led1OnOffStatus.ledOnOff;
  // Store the current status of LED1
  halCommonSetToken(TOKEN_LED1_ON_OFF, &led1OnOffStatus);

  //Reschedule the event after a delay of 1 seconds
  emberEventControlSetDelayMS(ledBlinkingEventControl, 2000);
}
