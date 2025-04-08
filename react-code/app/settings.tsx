import { Dimensions, SafeAreaView, Text, StyleSheet, TouchableOpacity, View} from "react-native";
import { useSharedValue } from "react-native-reanimated";
import Carousel, {
    ICarouselInstance,
    Pagination,
} from "react-native-reanimated-carousel";
import React from "react";

const data = [...new Array(15).keys()];
const width = Dimensions.get("window").width;
const height = Dimensions.get("window").height;

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
                <View style={{height: height * 2/10, justifyContent: "center", alignItems: "center"}}>
                    <Text style={styles.text}>Settings</Text>
                </View>


                <View style={{height: height / 2.5, borderStyle: "solid", borderWidth: 2, borderColor: "white", borderRadius: 7, justifyContent: "center", alignItems: "center"}}>
                    <Text>KACI</Text>
                </View>

                <View style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
                    <Carousel
                        ref={ref}
                        data={data}
                        width={width}
                        onProgressChange={(offset) => {
                            progress.value = offset;
                        }}
                        renderItem={({ item }: { item: number }) => (
                            <View style={{borderStyle: "solid", borderWidth: 2, borderColor: "white", borderRadius: 7, width: width*9/10, height: "75%" , justifyContent: "center", alignItems: "center"}}>
                                <Text style={{color: "white"}}>{item} Your mother</Text>
                                <Text style={{color: "white"}}>Palette ○○○○○○○○○○○○○○○○</Text>
                                <Text style={{color: "white"}}>Flashing Pattern: MOLD</Text>
                            </View>
                        )}
                        mode="parallax"
                        style={{height: height * 2 /10, justifyContent: "center", alignItems: "center"}}
                    />


                    {/*<Pagination.Basic
                        progress={progress}
                        data={data}
                        dotStyle={{ backgroundImage: "../assets/images/icon.png", backgroundSize: "auto", borderColor: "white", borderWidth: 2, borderStyle: "solid", borderRadius: 7, width: 50, height: 50,  }}
                        containerStyle={{ gap: 10, marginTop: 30, width: width, height: 55 }}

                        onPress={onPressPagination}
                        renderItem={( index ) => (
                            <View
                                style={{
                                    flex: 1,
                                    justifyContent: "center",
                                }}
                            >
                                <Text style={{ textAlign: "center", fontSize: 30, color: "#FFFFFF" }}>{index}</Text>
                            </View>
                        )}
                    />*/}
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
        height: height / 10,
        width: "100%",
    },
    notBackButton: {
        height: "90%",
    },
    TO: {
    }
});