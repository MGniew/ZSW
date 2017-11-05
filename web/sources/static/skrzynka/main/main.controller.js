(function() {
    'use strict';

    angular
        .module('skrzynka.main')
        .controller('MainController', MainController);

    MainController.$inject = [MainService];

    function MainController(MainService) {
        var vm = this;

        vm.message = "You don't have any letters...";
        vm.logo_path = "static/img/logo2.png";
        vm.check = check;
        
        init();

        //////////////

        function init() {
            check()
        }

        function check() {
            MainService.getMailboxStatus().then(function (response) {
                if (response.data == 1) {
                    vm.message = "You have new letters!";
                    vm.logo_path = "static/img/logo.png";
                } else {
                    vm.message = "You don't have any letters...";
                    vm.logo_path = "static/img/logo2.png";
                }
            })
        }


    }
})();