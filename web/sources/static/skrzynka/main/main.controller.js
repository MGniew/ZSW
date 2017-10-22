(function() {
    'use strict';

    angular
        .module('skrzynka.main')
        .controller('MainController', MainController);

    MainController.$inject = [MainService];

    function MainController(MainService) {
        var vm = this;

        vm.message = "You don't have any letters...";
        
        init();

        //////////////

        function init() {
            MainService.getMailboxStatus().then(function (response) {
                if (response.data == "1") {
                    vm.message = "You have new letters!"
                } else {
                    vm.message = "You don't have any letters..."
                }
            })
        }


    }
})();