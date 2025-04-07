import { Dimensions, SafeAreaView, Text, StyleSheet, TouchableOpacity, View} from "react-native";
import { useSharedValue } from "react-native-reanimated";
import Carousel, {
    ICarouselInstance,
    Pagination,
} from "react-native-reanimated-carousel";
import React from "react";

const data = [...new Array(6).keys()];
const width = Dimensions.get("window").width;

export default function Settings({navigation}: any) {
    const ref = React.useRef<ICarouselInstance>(null);
    const progress = useSharedValue<number>(0);

    const onPressPagination = (index: number) => {
        ref.current?.scrollTo({
            count: index - progress.value,
            animated: true,
        });
    };


    return (
        <SafeAreaView style={styles.container}>
            <View style={styles.backButton}>
            <TouchableOpacity style={styles.TO} onPress={() => navigation.navigate("Welcome")}>
                <Text style={{color: '#ffffff', textAlign: 'left', fontSize: 30}}>    ⟨    </Text>
            </TouchableOpacity>
            </View>
            <View style={styles.notBackButton}>
                <Text style={styles.text}>Settings</Text>

                <View style={{ flex: 1 }}>
                    <Carousel
                        ref={ref}
                        width={width}
                        height={width}
                        data={data}
                        onProgressChange={progress}
                        renderItem={({ index }) => (
                            <View
                                style={{
                                    flex: 1,
                                    borderWidth: 1,
                                    borderStyle: "solid",
                                    borderColor: "#ffffff",
                                    justifyContent: "center",
                                }}
                            >
                                <Text style={{ textAlign: "center", fontSize: 30, color: "#FFFFFF" }}>{index}</Text>
                            </View>
                        )}
                    />

                    <Pagination.Basic
                        progress={progress}
                        data={data}
                        dotStyle={{ backgroundColor: "#ffffff", borderRadius: 50 }}
                        containerStyle={{ gap: 10, marginTop: 20 }}
                        onPress={onPressPagination}
                    />
                </View>
            </View>
        </SafeAreaView>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        alignItems: 'center',
        justifyContent: 'center',
        backgroundColor: '#000000',
    },
    text: {
        fontFamily: "Thesignature",
        fontSize: 130,
        color: "#ffffff",
    },
    backButton: {
        height: "10%",
        width: "100%",
    },
    notBackButton: {
        height: "90%",
    },
    TO: {
    }
});