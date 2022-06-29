#include <MicroGUI.h>

// Store your MicroGUI in this json array
char json[] = "{\"ROOT\": {\"type\": {\"resolvedName\": \"CanvasArea\"},\"isCanvas\": true,\"props\": {\"id\": \"canvasElement\",\"width\": 480,\"height\": 320,\"background\": {\"r\": 245,\"g\": 166,\"b\": 35,\"a\": 1}},\"displayName\": \"Canvas\",\"custom\": {},\"hidden\": false,\"nodes\": [\"Textfield_1\",\"Switch_1\",\"Textfield_2\",\"Button_1\",\"Textfield_3\",\"Slider_1\",\"Textfield_4\",\"Checkbox_1\",\"Textfield_5\",\"Switch_2\",\"Button_2\"],\"linkedNodes\": {}},\"Textfield_1\": {\"type\": {\"resolvedName\": \"Textfield\"},\"isCanvas\": false,\"props\": {\"text\": \"This is some text\",\"fontSize\": 15,\"textAlign\": \"left\",\"fontWeight\": 500,\"width\": 40,\"height\": 30,\"color\": {\"r\": 255,\"g\": 255,\"b\": 255,\"a\": 1},\"pageX\": 181,\"pageY\": 28},\"displayName\": \"Textfield\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}},\"Switch_1\": {\"type\": {\"resolvedName\": \"Switch\"},\"isCanvas\": false,\"props\": {\"size\": \"small\",\"color\": {\"r\": 63,\"g\": 181,\"b\": 104,\"a\": 1},\"pageX\": 130,\"pageY\": 80.99998474121094},\"displayName\": \"Switch\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}},\"Textfield_2\": {\"type\": {\"resolvedName\": \"Textfield\"},\"isCanvas\": false,\"props\": {\"text\": \"These are\nswitches\",\"fontSize\": 15,\"textAlign\": \"left\",\"fontWeight\": 500,\"width\": 40,\"height\": 30,\"color\": {\"r\": 0,\"g\": 0,\"b\": 0,\"a\": 1},\"pageX\": 29,\"pageY\": 90.00001525878906},\"displayName\": \"Textfield\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}},\"Button_1\": {\"type\": {\"resolvedName\": \"Button\"},\"isCanvas\": false,\"props\": {\"text\": \"Knapp\",\"size\": \"small\",\"variant\": \"contained\",\"background\": {\"r\": 63,\"g\": 181,\"b\": 104,\"a\": 1},\"color\": {\"r\": 255,\"g\": 255,\"b\": 255,\"a\": 1},\"pageX\": 368,\"pageY\": 75.99998474121094},\"displayName\": \"Button\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}},\"Textfield_3\": {\"type\": {\"resolvedName\": \"Textfield\"},\"isCanvas\": false,\"props\": {\"text\": \"and these\nare buttons\",\"fontSize\": 15,\"textAlign\": \"left\",\"fontWeight\": 500,\"width\": 40,\"height\": 30,\"color\": {\"r\": 0,\"g\": 0,\"b\": 0,\"a\": 1},\"pageX\": 242,\"pageY\": 90.00001525878906},\"displayName\": \"Textfield\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}},\"Slider_1\": {\"type\": {\"resolvedName\": \"Slider\"},\"isCanvas\": false,\"props\": {\"size\": \"small\",\"width\": 204,\"value\": 78,\"min\": 0,\"max\": 100,\"color\": {\"r\": 241,\"g\": 27,\"b\": 245,\"a\": 1},\"valueLabelDisplay\": \"auto\",\"pageX\": 238,\"pageY\": 178.99998474121094},\"displayName\": \"Slider\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}},\"Textfield_4\": {\"type\": {\"resolvedName\": \"Textfield\"},\"isCanvas\": false,\"props\": {\"text\": \"Here we have a slider\",\"fontSize\": 15,\"textAlign\": \"left\",\"fontWeight\": 500,\"width\": 40,\"height\": 30,\"color\": {\"r\": 0,\"g\": 0,\"b\": 0,\"a\": 1},\"pageX\": 31,\"pageY\": 178.99998474121094},\"displayName\": \"Textfield\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}},\"Checkbox_1\": {\"type\": {\"resolvedName\": \"Checkbox\"},\"isCanvas\": false,\"props\": {\"size\": \"small\",\"color\": {\"r\": 251,\"g\": 255,\"b\": 1,\"a\": 1},\"pageX\": 310,\"pageY\": 246.00001525878906},\"displayName\": \"Checkbox\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}},\"Textfield_5\": {\"type\": {\"resolvedName\": \"Textfield\"},\"isCanvas\": false,\"props\": {\"text\": \"And last but not least, a checkbox\",\"fontSize\": 15,\"textAlign\": \"left\",\"fontWeight\": 500,\"width\": 40,\"height\": 30,\"color\": {\"r\": 0,\"g\": 0,\"b\": 0,\"a\": 1},\"pageX\": 33,\"pageY\": 246.99998474121094},\"displayName\": \"Textfield\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}},\"Switch_2\": {\"type\": {\"resolvedName\": \"Switch\"},\"isCanvas\": false,\"props\": {\"size\": \"small\",\"color\": {\"r\": 63,\"g\": 81,\"b\": 181,\"a\": 1},\"pageX\": 130,\"pageY\": 117.99998474121094},\"displayName\": \"Switch\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}},\"Button_2\": {\"type\": {\"resolvedName\": \"Button\"},\"isCanvas\": false,\"props\": {\"text\": \"Button\",\"size\": \"small\",\"variant\": \"contained\",\"background\": {\"r\": 63,\"g\": 81,\"b\": 181,\"a\": 1},\"color\": {\"r\": 255,\"g\": 255,\"b\": 255,\"a\": 1},\"pageX\": 368,\"pageY\": 115.99998474121094},\"displayName\": \"Button\",\"custom\": {},\"parent\": \"ROOT\",\"hidden\": false,\"nodes\": [],\"linkedNodes\": {}}}";


void setup(void)
{
  Serial.begin(115200); /* prepare for possible serial debug */

  mgui_init(json);
}

void loop()
{
  MGUI_event latest = mgui_run();
  Serial.println(latest.getName());
  Serial.println(latest.getValue());

  delay(100);
}