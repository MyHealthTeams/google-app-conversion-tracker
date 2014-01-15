(function(){

  function GAPPtracker() {}

  GAPPtracker.prototype.track = function(conversion_id, label, value, repeatable, success, fail) {
    cordova.exec(success, fail, "GoogleAppTracking", "track", [conversion_id, label, value, repeatable]);
  };

  window.GAPPtracker = new GAPPtracker();
  window.plugins = window.plugins || {};
  window.plugins.gapptracker = window.GAPPtracker;

})();

