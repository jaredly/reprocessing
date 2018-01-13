
let first = ref(true);
let checkRebuild = (filePath) => {
  if (first^) {
    first := false;

    [%bs.raw{|
      function() {
        console.log ("live life good")
        var waitAndEval = () => {
          fetch("/hot.js")
            .then(res => res.text())
            .then(code => {
              eval(code);
              waitAndEval();
            })
        };
        waitAndEval()
      }()
    |}]
  }
};
