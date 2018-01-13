let module NoHotreloading = {
  let checkRebuild = (filePath) =>
  failwith("Hotreload not supported for native, compile to web or bytecode.");
};

include [%matchenv
  switch BSB_BACKEND {
  | "bytecode" => Reprocessing_Hotreload_Native
  | "native" => NoHotreloading
  | "js" => Reprocessing_Hotreload_Web
  | "native-android" => NoHotreloading
  | "byte-android" => Reasongl_Hotreload
  | "native-ios" => NoHotreloading
  | "byte-ios" => Reasongl_Hotreload
  }
];