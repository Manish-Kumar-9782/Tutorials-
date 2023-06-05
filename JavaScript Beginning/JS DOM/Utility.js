
class LocalDatabase {
    /**
     * This class will be used to perform operations related to the localStorage, it will 
     * Take care of the required functionality working with the localStorage database.
     * 
     * In this we will take care of reading, writing and updating and deleting data from 
     * local storage.
     */

    static DatabaseKey = 'database'; // it must contain the name of the database.
    static Records = []; // it must contain the instance of the class or subclass.
    static RowRecord = null;
    // it will be our row object retrieved form the database.
    static UniqueId = 1;
    static Fields = ["id", "regDate", "updateDate"]; // it must contain the all fields which are going to be stored in the database.
    // this will hold the bsModal which to get the book issue details.
    constructor({ id = 0, regDate = null, updateDate = null }) {
        if (id) {
            // if id is already in the with the already stored data, then we need 
            // use that existing id.
            this.id = id;
            this.constructor.setId(id);
            this.constructor.increaseId();
        }
        else {
            // if id is not in the database, then we need to create one.
            this.id = this.constructor.increaseId();
        }

        if (regDate) {
            // if registration date is given then we need to use that existing date.
            this.regDate = regDate;
        }
        else {
            let date = new Date()
            this.regDate = date.toISOString;
        }

        if (updateDate) {
            // if an update date is given then we need to use that existing date.
            this.updateDate = updateDate;
        }
        else {
            this.updateDate = null;
        }

        this.constructor.pushRecord(this)

    }

    static setId(id) {
        this.UniqueId = id;
    }

    static increaseId() {
        return this.UniqueId++;
    }

    static pushRecord(record) {
        this.Records.push(record)
    }

    static setRecord(key, value) {
        /**
         * this function will be used to store the data in key value pair to the local storage.
         */
        let data = JSON.stringify(value);
        localStorage.setItem(key, data);
    }


    static getRecord(key) {
        /**
         * this function will be used to get the data in key value pair form local storage.
         */
        let data = localStorage.getItem(key)
        if (data) {
            return JSON.parse(data)
        }
        return { "fields": this.Fields, values: [] }
    }

    updateField(key, value) {
        // a method that updates the instance data field with given value.
        this[key] = value;
    }

    static getFields() {
        return this.Fields;
    }

    static getDatabaseKey() {
        return this.DatabaseKey;
    }

    // a method to get the instance by using its id value.
    static get(id) {
        for (let instance of this.Records) {
            if (instance.id == id) {
                return instance;
            }
        }
    }

    static saveAll() {
        // a method to save the all instance to the database with current data.
        let data = {
            "fields": this.Fields,
            'values': this.Records.map((record) => record.toArray())
        }
        this.setRecord(this.DatabaseKey, data)
    }

}


