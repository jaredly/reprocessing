
let first = ref(true);
let checkRebuild = (filePath) => {
  if (first^) {
    first := false;

    let startHot: string => unit = [%bs.raw{|
      function(filePath) {
        console.log ("live life good")
        var suffix = Math.random().toString(16).slice(2);
        var waitAndEval = (first) => {
          fetch((first ? "/hot-first/" : "/hot/") + filePath + "?" + suffix)
            .then(res => res.text())
            .then(code => {
              eval(code);
              waitAndEval(false);
            })
        };
        waitAndEval(true)
      }
    |}];
    startHot(filePath)
  };
  false
};
