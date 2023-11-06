// SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.7.0 <0.9.0;

/** 
 * @title Ballot
 * @dev Implements voting process along with vote delegation
 */

contract Simplebank{
    struct client_account {
        int client_id;
        address client_address;
        uint client_balance_in_ether;
    }

    client_account[] clients;

    int clientCounter;
    address payable manager;

    modifier  onlyManager() {
        require(msg.sender == manager,"only manager can call this!");
        _;
    }

    modifier  onlyClients() {
        bool isClient = false;

        for(uint i=0; i<clients.length; i++) {
            if(clients[i].client_address == msg.sender) {
                isClient = true;
                break;
            }
        }
        require(isClient, "only clients cal call this!");
        _;
    }

    constructor() {
        clientCounter = 0;
    }
    receive() external payable { }

    function setManager(address ManagerAddress) public returns(string memory) {
        manager = payable (ManagerAddress);

        return " ";
    }

    function joinAsClient() public payable returns(string memory) {
        clients.push(client_account(clientCounter++, msg.sender, address(msg.sender).balance));
        return " ";
    }

    function deposit() public payable onlyClients {
        payable(address(this)).transfer(msg.value);
    }

    function withdraw(uint amount) public payable onlyClients{
        payable(msg.sender).transfer(amount*1 ether);
    }

    function sendInterest() public payable onlyManager {
        for(uint i=0; i<clients.length; i++) {
            address initialAddress=clients[i].client_address;

            payable(initialAddress).transfer(1 ether);
        }
    }

    function getContractBalance() public view returns(uint) {
        return address(this).balance;
    }
}