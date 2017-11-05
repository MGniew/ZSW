(function() {
    'use strict';

    angular
        .module('skrzynka.main')
        .service('MainService', MainService);

    MainService.$inject = ['$http', '$q'];

    function MainService($http, $q) {
        var service = {
            getMailboxStatus: getMailboxStatus
        };

        return service;
        ////////////////
        
        function getMailboxStatus() {
            return $http.get("http://192.168.1.3:5000/state")
                .then(handleResponse())
                .catch(handleError('An error occurred while getting user data by session:'));

        }

        function handleResponse(msg) {
            return function(response) {
                if(msg) console.log(msg, response);
                return response;
            };
        }

        function handleError(msg) {
            return function(error) {
                if(msg) console.error(msg, error);
                return $q.reject(error);
            }
        }
    }
})();
