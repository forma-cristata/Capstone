import {StyleSheet, SafeAreaView, TouchableOpacity, View, Text} from "react-native";

export default function ChooseModificatioon({navigation}: any) {

    return (
        <SafeAreaView style={styles.container}>
            {/*Back Button*/}
            <View style={styles.backButton}>
                <TouchableOpacity onPress={() => navigation.navigate("Settings")}>
                    <Text style={styles.backB}>    ⟨    </Text>
                </TouchableOpacity>
            </View>


        </SafeAreaView>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: "#000000",
    },
    backButton: {
        position: "absolute",
        top: 50,
        left: 20,
    },
    notBackButton: {
        flex: 1,
        justifyContent: "center",
        alignItems: "center",
    },
    title: {
        marginTop: 50,
    },
    text: {
        color: "white",
        fontSize: 30,
    },
    backB: {
        color: "white",
        fontSize: 30,
    },
})