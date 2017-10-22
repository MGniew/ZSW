(function(){
  'use strict';

  angular
      .module('skrzynka')
      .config(config);

  config.$inject = ['$routeProvider'];

  function config($routeProvider) {
      $routeProvider
          .when('/', {
              templateUrl: 'static/skrzynka/main/main.view.html'
          })

          .otherwise({
              redirectTo: '/'
          });
  }
})();
